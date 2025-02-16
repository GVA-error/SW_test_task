#pragma once

#include <memory>

#include "Entities/UnitEnums.hpp"
#include "Entities/Unit.hpp"
#include "Entities/UnitsHeap.hpp"
#include "Entities/GameField.hpp"
#include "Mechanics/MechanicsResult/RangeAttackResult.hpp"

// Механики обеспечивающие дальний бой
// Дальняя атака, случайная ближняя атака, провоцированная ближняя атака и т. п.
namespace sw::mechanics
{
    using namespace sw::entities;

    // Пробуем атаковать случайного юнита в радиусе атаки.
    // DAMAGE_STAT - атрибут для просчёта урона
    // см. sw::entities::UnitAttributes
    RangeAttackResult tryToRandomRangeAttack(std::shared_ptr<sw::entities::GameField>&, std::shared_ptr<UnitHeap>&,
                                             sw::entities::Unit&, const UnitAttributes& DAMAGE_STAT);

}

