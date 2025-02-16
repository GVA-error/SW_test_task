#pragma once

#include <memory>

#include "entities/UnitEnums.h"
#include "entities/Unit.h"
#include "entities/unitsheap.h"
#include "entities/gamefield.h"
#include "mechanics/mechanicsresults.h"

// Механики обеспечивающие дальний бой
// Дальняя атака, случайная ближняя атака, провоцированная ближняя атака и т. п.
namespace sw::mechanics
{
    using namespace sw::entities;

    struct RangeAttackResult : DefaultAttackResult
    {
    };

    // Пробуем атаковать случайного юнита в радиусе атаки.
    // DAMAGE_STAT - атрибут для просчёта урона
    // см. sw::entities::UnitAttributes
    RangeAttackResult tryToRandomRangeAttack(std::shared_ptr<sw::entities::GameField>&, std::shared_ptr<UnitHeap>&,
                                             sw::entities::Unit&, const UnitAttributes& DAMAGE_STAT);

}

