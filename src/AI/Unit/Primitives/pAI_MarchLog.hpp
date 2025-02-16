#pragma once

#include <assert.h>

#include <IO/System/EventLog.hpp>
#include <IO/System/EventLog.hpp>

#include "Mechanics/MechanicsResult/MarchResult.hpp"

// вывод лога для марша
namespace sw::AI::primitive
{
    void pAI_MoveLog(mechanics::MarchResult&, uint32_t tickNumber, sw::EventLog& eventLog);

    void pAI_MarchStartLog(mechanics::MarchResult&, uint32_t tickNumber, sw::EventLog& eventLog);
}

