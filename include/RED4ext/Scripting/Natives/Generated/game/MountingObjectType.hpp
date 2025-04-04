#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
namespace RED4ext
{
namespace game {
enum class MountingObjectType : uint32_t
{
    Object = 0,
    Vehicle = 1,
    Puppet = 2,
    Platform = 3,
    Invalid = 4294967295,
};
} // namespace game
using gameMountingObjectType = game::MountingObjectType;
} // namespace RED4ext

// clang-format on
