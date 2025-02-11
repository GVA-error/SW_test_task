#ifndef RANGEATTACK_H
#define RANGEATTACK_H


#include <memory>

#include "entities/gamefield.h"
#include "entities/Unit.h"
#include "entities/UnitEnums.h"

// Механики обеспечивающие дальний бой
// Дальняя атака, случайная ближняя атака, провоцированная ближняя атака и т. п.
namespace sw::mechanics
{
    using namespace sw::entities;
    // Пробуем атаковать ближайшего юнита.
    // DAMAGE_STAT - атрибут для просчёта урона
    // см. sw::entities::UnitAttributes
    // Если никто не был атакован вернёт false
    // out_attackedUnit - будет присвоен id юнита которого атаковали
    bool tryToRandomRangeAttack(std::shared_ptr<sw::entities::GameField>&, sw::entities::Unit&, UnitAttributes& DAMAGE_STAT, uint32_t& out_attackedUnit);

}

#endif // RANGEATTACK_H
