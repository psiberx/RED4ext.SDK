#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
namespace RED4ext
{
namespace anim {
enum class MotionTableAction : int32_t
{
    MTA_None = 0,
    MTA_Start = 1,
    MTA_Stop = 2,
    MTA_Move = 3,
    MTA_TurnInPlace = 4,
    MTA_TransitionToBackward = 5,
    MTA_BackwardMove = 6,
    MTA_TransitionFromBackward = 7,
    MTA_StrafeLeft = 8,
    MTA_StrafeRight = 9,
    MTA_ForwardToStrafeLeft = 10,
    MTA_ForwardToStrafeRight = 11,
    MTA_StrafeLeftToForward = 12,
    MTA_StrafeRightToForward = 13,
    MTA_BackwardToStrafeLeft = 14,
    MTA_BackwardToStrafeRight = 15,
    MTA_StrafeLeftToBackward = 16,
    MTA_StrafeRightToBackward = 17,
    MTA_BackwardStart = 18,
    MTA_BackwardStop = 19,
    MTA_StrafeLeftStart = 20,
    MTA_StrafeLeftStop = 21,
    MTA_StrafeRightStart = 22,
    MTA_StrafeRightStop = 23,
    MTA_ForwardToWalk = 24,
    MTA_ForwardToJog = 25,
    MTA_ForwardToSprint = 26,
    MTA_HardStopLeftLeg = 27,
    MTA_HardStopRightLeg = 28,
    MTA_RepositionForward = 29,
    MTA_RepositionLeft = 30,
    MTA_RepositionRight = 31,
    MTA_RepositionBackward = 32,
    MTA_Custom = 33,
    MTA_CrowdMove = 34,
    MTA_CrowdMoveSlopes = 35,
    MTA_CrowdMoveStairs = 36,
    MTA_StrafeLeftToStrafeRight = 37,
    MTA_StrafeRightToStrafeLeft = 38,
    MTA_CrowdRelaxedStop = 39,
    MTA_CrowdHardStop = 40,
    MTA_CrowdSprintStop = 41,
    MTA_CrowdFleeStopFront = 42,
    MTA_CrowdFleeStopBack = 43,
    MTA_CrowdRelaxedStart = 44,
    MTA_CrowdFleeStartIdle = 45,
    MTA_CrowdFleeStartMotion = 46,
    MTA_CrowdDirectionalStartFast = 47,
};
} // namespace anim
using animMotionTableAction = anim::MotionTableAction;
} // namespace RED4ext

// clang-format on
