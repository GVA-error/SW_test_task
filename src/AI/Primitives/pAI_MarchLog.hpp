#pragma once

#include <IO/System/EventLog.hpp>
#include <IO/System/EventLog.hpp>

#include "Entities/Unit.hpp"
#include "Mechanics/MechanicsResult/MarchResult.hpp"

// вывод лога для шага марша
namespace sw::AI::primitive
{
    using namespace sw::entities;
    void pAI_MoveLog(const Unit&, mechanics::MarchResult&, uint32_t tickNumber, sw::EventLog& eventLog);
}

