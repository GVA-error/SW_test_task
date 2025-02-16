#pragma once

#include <memory>

#include "entities/gamefield.h"
#include "entities/Unit.h"
#include "entities/UnitEnums.h"
#include "entities/unitsheap.h"
#include "mechanics/mechanicsresults.h"
#include "mechanics/attack.h"

// Механики обеспечивающие ближний бой
// Ближняя атака, случайная ближняя атака, провоцированная ближняя атака и т. п.
namespace sw::mechanics
{
    using namespace sw::entities;

    struct MeleeAttackResult : DefaultAttackResult
    {
    };

    // Пробуем атаковать ближайшего юнита.
    // DAMAGE_STAT - атрибут для просчёта урона
    // см. sw::entities::UnitAttributes
    MeleeAttackResult tryToRandomMeleeAttack(std::shared_ptr<GameField>&, std::shared_ptr<UnitHeap>&, Unit& attacker,
                                const UnitAttributes& DAMAGE_STAT);
}

