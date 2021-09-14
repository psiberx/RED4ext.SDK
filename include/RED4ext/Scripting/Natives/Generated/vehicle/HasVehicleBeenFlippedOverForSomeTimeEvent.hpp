#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/Event.hpp>

namespace RED4ext
{
namespace vehicle { 
struct HasVehicleBeenFlippedOverForSomeTimeEvent : red::Event
{
    static constexpr const char* NAME = "vehicleHasVehicleBeenFlippedOverForSomeTimeEvent";
    static constexpr const char* ALIAS = "HasVehicleBeenFlippedOverForSomeTimeEvent";

};
RED4EXT_ASSERT_SIZE(HasVehicleBeenFlippedOverForSomeTimeEvent, 0x40);
} // namespace vehicle
using HasVehicleBeenFlippedOverForSomeTimeEvent = vehicle::HasVehicleBeenFlippedOverForSomeTimeEvent;
} // namespace RED4ext
