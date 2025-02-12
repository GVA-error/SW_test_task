#ifndef MELEEATTACK_H
#define MELEEATTACK_H

#include <memory>

#include "entities/gamefield.h"
#include "entities/Unit.h"
#include "entities/UnitEnums.h"
#include "mechanics/mechanicsresults.h"

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
    MeleeAttackResult tryToRandomMeleeAttack(std::shared_ptr<GameField>&, Unit& attacker,
                                const UnitAttributes& DAMAGE_STAT);
}

#endif // MELEEATTACK_H
