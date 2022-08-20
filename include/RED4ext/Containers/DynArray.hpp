#pragma once

#include <algorithm>
#include <cstdint>
#include <functional>
#include <type_traits>

#include <RED4ext/Addresses.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/Iterators/DynArrayIters.hpp>
#include <RED4ext/Relocation.hpp>

namespace RED4ext
{
namespace Memory
{
struct IAllocator;
}

template<typename T>
struct DynArray
{
    using ValueType = T;
    using Pointer = T*;
    using ConstPointer = const T*;
    using Reference = T&;
    using ConstReference = const T&;
    using SizeType = std::uint32_t;
    using DifferenceType = std::ptrdiff_t;

    using Iterator = DynArrayIter<DynArray<T>>;
    using ConstIterator = DynArrayConstIter<DynArray<T>>;
    using ReverseIterator = std::reverse_iterator<Iterator>;
    using ConstReverseIterator = std::reverse_iterator<ConstIterator>;

    DynArray(Memory::IAllocator* aAllocator = nullptr)
        : entries(aAllocator ? *reinterpret_cast<T**>(aAllocator) : nullptr)
        , size(0)
        , capacity(0)
    {
    }

    const T& operator[](SizeType aIndex) const
    {
        return entries[aIndex];
    }

    T& operator[](SizeType aIndex)
    {
        return entries[aIndex];
    }

    void PushBack(const T& aItem)
    {
        EmplaceBack(std::forward<const T&>(aItem));
    }

    void PushBack(T&& aItem)
    {
        EmplaceBack(std::forward<T&&>(aItem));
    }

    template<class... TArgs>
    void EmplaceBack(TArgs&&... aArgs)
    {
        Emplace(end(), std::forward<TArgs>(aArgs)...);
    }

    template<class... TArgs>
    void Emplace(ConstIterator aPosition, TArgs&&... aArgs)
    {
        uint32_t posIdx = static_cast<uint32_t>(aPosition - begin());
        uint32_t newSize = size + 1;
        if (newSize > capacity)
        {
            Reserve(newSize);
        }

        // If not at the end
        if (posIdx != size)
        {
            uint32_t entriesCount = size - posIdx;
            MoveEntries(&entries[posIdx], &entries[posIdx + 1], entriesCount);
        }

        new (&entries[posIdx]) T(std::forward<TArgs>(aArgs)...);
        size = newSize;
    }

    bool Remove(const T& aItem)
    {
        for (uint32_t i = 0; i != size; ++i)
        {
            if (aItem == entries[i])
            {
                return RemoveAt(i);
            }
        }

        return false;
    }

    bool RemoveAt(SizeType aIndex)
    {
        if (aIndex >= size)
            return false;

        entries[aIndex].~T();
        if ((aIndex + 1) != size) // If not at the end
        {
            SizeType entriesCount = size - (aIndex + 1);
            MoveEntries(&entries[aIndex + 1], &entries[aIndex], entriesCount);
        }
        --size;
        return true;
    }

    void Clear()
    {
        for (SizeType i = 0; i != size; ++i)
        {
            entries[i].~T();
        }

        size = 0;
    }

    void Reserve(SizeType aCount)
    {
        // Alignment seems to always be 8.
        constexpr uint32_t alignment = 8;

        auto newCapacity = CalculateGrowth(aCount);
        using func_t = void (*)(DynArray * aThis, uint32_t aCapacity, uint32_t aElementSize, uint32_t aAlignment,
                                void (*a5)(int64_t, int64_t, int64_t, int64_t));

        RelocFunc<func_t> func(Addresses::DynArray_Realloc);
        func(this, newCapacity, sizeof(T), alignment, nullptr);
    }

    Memory::IAllocator* GetAllocator()
    {
        if (capacity == 0)
            return reinterpret_cast<Memory::IAllocator*>(&entries);
        else
            return reinterpret_cast<Memory::IAllocator*>(&entries[capacity]);
    }

    [[nodiscard]] constexpr Iterator Begin() noexcept
    {
        return Iterator(entries);
    }

    [[nodiscard]] constexpr ConstIterator Begin() const noexcept
    {
        return ConstIterator(entries);
    }

    [[nodiscard]] constexpr Iterator End() noexcept
    {
        return Iterator(entries + size);
    }

    [[nodiscard]] constexpr ConstIterator End() const noexcept
    {
        return ConstIterator(entries + size);
    }

#pragma region STL
    [[nodiscard]] constexpr Iterator begin() noexcept
    {
        return Begin();
    }

    [[nodiscard]] constexpr ConstIterator begin() const noexcept
    {
        return Begin();
    }

    [[nodiscard]] constexpr Iterator end() noexcept
    {
        return End();
    }

    [[nodiscard]] constexpr ConstIterator end() const noexcept
    {
        return End();
    }
#pragma endregion

    T* entries;        // 00
    uint32_t capacity; // 08
    uint32_t size;     // 0C

private:
    void MoveEntries(T* aSrc, T* aDst, SizeType aCount)
    {
        if (aCount == 0 || aSrc == aDst)
            return;

        if constexpr (std::is_trivially_copyable_v<T>)
        {
            std::memmove(aDst, aSrc, aCount * sizeof(T));
        }
        else if (aSrc < aDst)
        {
            for (; aCount != 0; --aCount)
            {
                new (&aDst[aCount - 1]) T(std::move(aSrc[aCount - 1]));
                aSrc[aCount - 1].~T();
            }
        }
        else
        {
            for (uint32_t i = 0; i != aCount; ++i)
            {
                new (&aDst[i]) T(std::move(aSrc[i]));
                aSrc[i].~T();
            }
        }
    }

    SizeType CalculateGrowth(SizeType aNewSize)
    {
        SizeType growth = capacity + (capacity / 2);
        if (growth < aNewSize)
        {
            return aNewSize;
        }

        return growth;
    }
};
RED4EXT_ASSERT_SIZE(DynArray<void*>, 0x10);
RED4EXT_ASSERT_OFFSET(DynArray<void*>, capacity, 0x8);
RED4EXT_ASSERT_OFFSET(DynArray<void*>, size, 0xC);
} // namespace RED4ext