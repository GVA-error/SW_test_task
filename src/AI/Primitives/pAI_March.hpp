#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>
#include <IO/System/EventLog.hpp>

#include "Entities/Unit.hpp"
#include "Entities/GameField.hpp"

// Описывем как АИ использует механики марша.
namespace sw::AI::primitive
{
    using namespace sw::entities;
    bool pAI_tryToStep(std::shared_ptr<GameField>& gf, Unit& u,
                         uint32_t tickNumber, sw::EventLog& eventLog);
}
