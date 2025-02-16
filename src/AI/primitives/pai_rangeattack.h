#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>
#include <IO/System/EventLog.hpp>

#include "entities/UnitEnums.h"
#include "entities/Unit.h"
#include "entities/unitsheap.h"
#include "entities/gamefield.h"

// Описывем как АИ использует механики дальнего боя.
namespace sw::AI::primitive
{
    using namespace sw::entities;
    bool pAI_tryToRangeAttack(std::shared_ptr<GameField>&, std::shared_ptr<UnitHeap>&, Unit&,
                              uint32_t tickNumber, sw::EventLog&, UnitAttributes DAMAGE_STAT);


}
