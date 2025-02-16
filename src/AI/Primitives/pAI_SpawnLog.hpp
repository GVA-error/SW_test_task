#pragma once

#include <IO/System/EventLog.hpp>
#include <IO/System/EventLog.hpp>

#include "Mechanics/MechanicsResult/SpawnResult.hpp"

// вывод лога для создания юнита
namespace sw::AI::primitive
{
    void pAI_SpawnLog(mechanics::SpawnResult&, uint32_t tickNumber, sw::EventLog& eventLog);
}

