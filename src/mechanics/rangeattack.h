#ifndef RANGEATTACK_H
#define RANGEATTACK_H


#include <memory>

#include "entities/gamefield.h"
#include "entities/Unit.h"
#include "entities/UnitEnums.h"
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
    RangeAttackResult tryToRandomRangeAttack(std::shared_ptr<sw::entities::GameField>&, sw::entities::Unit&,
                                const UnitAttributes& DAMAGE_STAT);

}

#endif // RANGEATTACK_H
