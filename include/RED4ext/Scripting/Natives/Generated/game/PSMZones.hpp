#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
namespace RED4ext
{
namespace game {
enum class PSMZones : uint32_t
{
    Default = 0,
    Public = 1,
    Safe = 2,
    Restricted = 3,
    Dangerous = 4,
    Any = 4294967295,
};
} // namespace game
using gamePSMZones = game::PSMZones;
} // namespace RED4ext

// clang-format on
