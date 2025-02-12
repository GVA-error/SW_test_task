#ifndef PAI_MELEEATTACK_H
#define PAI_MELEEATTACK_H

#include <memory>

#include "IO/System/EventLog.hpp"
#include "entities/gamefield.h"
#include "entities/Unit.h"
#include "IO/System/EventLog.hpp"
#include "entities/UnitEnums.h"

// Описывем как АИ использует механики ближнего боя.
namespace sw::AI::primitive
{
    using namespace sw::entities;
    bool pAI_tryToMeleeAttack(std::shared_ptr<GameField>& gf, Unit& u,
                     uint32_t tickNumber, sw::EventLog& eventLog, UnitAttributes DAMAGE_STAT);

}

#endif // PAI_MELEEATTACK_H
