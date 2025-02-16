#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>
#include <IO/System/EventLog.hpp>

#include "Entities/Unit.hpp"
#include "Entities/UnitsHeap.hpp"
#include "Entities/GameField.hpp"

// Описывем как АИ использует механики ближнего боя.
namespace sw::AI::primitive
{
    using namespace sw::entities;
    bool pAI_tryToMeleeAttack(std::shared_ptr<GameField>&, std::shared_ptr<UnitHeap>&, Unit&,
                     uint32_t tickNumber, sw::EventLog&, UnitAttributes DAMAGE_STAT);

}
