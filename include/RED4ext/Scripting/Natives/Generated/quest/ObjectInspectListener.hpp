#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IInspectListener.hpp>

namespace RED4ext
{
namespace quest { 
struct ObjectInspectListener : quest::IInspectListener
{
    static constexpr const char* NAME = "questObjectInspectListener";
    static constexpr const char* ALIAS = "ObjectInspectListener";

    uint8_t unk40[0x50 - 0x40]; // 40
};
RED4EXT_ASSERT_SIZE(ObjectInspectListener, 0x50);
} // namespace quest
using ObjectInspectListener = quest::ObjectInspectListener;
} // namespace RED4ext

// clang-format on
