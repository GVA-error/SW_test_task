#ifndef MELEEATTACK_H
#define MELEEATTACK_H

#include <cstdint>
#include <memory>

#include "entities/gamefield.h"
#include "entities/Unit.h"
#include "entities/UnitEnums.h"

// Механики обеспечивающие ближний бой
// Ближняя атака, случайная ближняя атака, провоцированная ближняя атака и т. п.

namespace sw::mechanics
{
    using namespace sw::entities;
    // Пробуем атаковать ближайшего юнита.
    // DAMAGE_STAT - атрибут для просчёта урона
    // см. sw::entities::UnitAttributes
    // Если никто не был атакован вернёт false
    // out_attackedUnit - будет присвоен id юнита которого атаковали
    bool tryToRandomMeleeAttack(std::shared_ptr<GameField>&, Unit& attacker, UnitAttributes& DAMAGE_STAT, uint32_t& out_attackedUnit);
}

#endif // MELEEATTACK_H
