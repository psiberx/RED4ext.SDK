#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/Event.hpp>

namespace RED4ext
{
namespace game::ui
{
struct SetSelectedNpcEvent : red::Event
{
    static constexpr const char* NAME = "gameuiSetSelectedNpcEvent";
    static constexpr const char* ALIAS = "SetSelectedNpcEvent";

    uint8_t unk40[0x48 - 0x40]; // 40
};
RED4EXT_ASSERT_SIZE(SetSelectedNpcEvent, 0x48);
} // namespace game::ui
using gameuiSetSelectedNpcEvent = game::ui::SetSelectedNpcEvent;
using SetSelectedNpcEvent = game::ui::SetSelectedNpcEvent;
} // namespace RED4ext

// clang-format on
