#pragma once

#include <memory>

#include "Entities/Unit.hpp"
#include "Entities/UnitEnums.hpp"
#include "Entities/UnitsHeap.hpp"
#include "Entities/GameField.hpp"
#include "Mechanics/MechanicsResult/MeleeAttackResult.hpp"

// Механики обеспечивающие ближний бой
// Ближняя атака, случайная ближняя атака, провоцированная ближняя атака и т. п.
namespace sw::mechanics
{
    using namespace sw::entities;

    // Пробуем атаковать ближайшего юнита.
    // DAMAGE_STAT - атрибут для просчёта урона
    // см. sw::entities::UnitAttributes
    MeleeAttackResult tryToRandomMeleeAttack(std::shared_ptr<GameField>&, std::shared_ptr<UnitHeap>&, Unit& attacker,
                                const UnitAttributes& DAMAGE_STAT);
}

