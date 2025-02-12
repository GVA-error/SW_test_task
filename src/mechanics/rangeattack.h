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

    struct RangeAttackResult
    {
        uint32_t targetUnit   = UNDEFINED_UNIT_ID; // id юнита которого атаковали.
        uint32_t damage       = 0;                 // размер полученного урона.
        uint32_t targetHp     = 0;                 // сколько хп осталось у атакуемого
        bool     f_unitDied   = false;             // юнит мёртв.
        bool     f_activity   = false;             // была ли произведена атака.
    };

    // Пробуем атаковать случайного юнита в радиусе атаки.
    // DAMAGE_STAT - атрибут для просчёта урона
    // см. sw::entities::UnitAttributes
    RangeAttackResult tryToRandomRangeAttack(std::shared_ptr<sw::entities::GameField>&, sw::entities::Unit&,
                                const UnitAttributes& DAMAGE_STAT);

}

#endif // RANGEATTACK_H
