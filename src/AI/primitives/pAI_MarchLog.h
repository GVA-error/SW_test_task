#pragma once

#include <IO/System/EventLog.hpp>
#include <IO/System/EventLog.hpp>

#include "entities/Unit.h"
#include "mechanics/mechanicsresults.h"

// вывод лога для атак
namespace sw::AI::primitive
{
    using namespace sw::entities;
    void pAI_MoveLog(const Unit& u, mechanics::MarchResult& moveRes, uint32_t tickNumber, sw::EventLog& eventLog);
}

