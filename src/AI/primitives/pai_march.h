#pragma once

#include <memory>

#include "IO/System/EventLog.hpp"
#include "entities/gamefield.h"
#include "entities/Unit.h"
#include "IO/System/EventLog.hpp"

// Описывем как АИ использует механики марша.
namespace sw::AI::primitive
{
    using namespace sw::entities;
    bool pAI_tryToStep(std::shared_ptr<GameField>& gf, Unit& u,
                         uint32_t tickNumber, sw::EventLog& eventLog);
}
