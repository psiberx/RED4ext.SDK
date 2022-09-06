#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetLogicController.hpp>

namespace RED4ext
{
namespace ink::anim { 
struct AnimationController : ink::WidgetLogicController
{
    static constexpr const char* NAME = "inkanimAnimationController";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk78[0xA8 - 0x78]; // 78
};
RED4EXT_ASSERT_SIZE(AnimationController, 0xA8);
} // namespace ink::anim
} // namespace RED4ext

// clang-format on
