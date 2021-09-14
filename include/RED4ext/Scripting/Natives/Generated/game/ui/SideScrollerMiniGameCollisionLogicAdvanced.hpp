#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetLogicController.hpp>

namespace RED4ext
{
namespace game::ui { 
struct SideScrollerMiniGameCollisionLogicAdvanced : ink::WidgetLogicController
{
    static constexpr const char* NAME = "gameuiSideScrollerMiniGameCollisionLogicAdvanced";
    static constexpr const char* ALIAS = "MinigameCollisionLogicAdvanced";

    uint8_t unk68[0xB0 - 0x68]; // 68
};
RED4EXT_ASSERT_SIZE(SideScrollerMiniGameCollisionLogicAdvanced, 0xB0);
} // namespace game::ui
using MinigameCollisionLogicAdvanced = game::ui::SideScrollerMiniGameCollisionLogicAdvanced;
} // namespace RED4ext
