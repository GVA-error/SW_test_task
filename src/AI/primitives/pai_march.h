#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>
#include <IO/System/EventLog.hpp>

#include "entities/Unit.h"
#include "entities/gamefield.h"

// Описывем как АИ использует механики марша.
namespace sw::AI::primitive
{
    using namespace sw::entities;
    bool pAI_tryToStep(std::shared_ptr<GameField>& gf, Unit& u,
                         uint32_t tickNumber, sw::EventLog& eventLog);
}
