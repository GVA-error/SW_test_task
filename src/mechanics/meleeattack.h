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

    struct MeleeAttackResult
    {
        uint32_t targetUnit   = UNDEFINED_UNIT_ID; // id юнита которого атаковали.
        uint32_t damage       = 0;                 // размер полученного урона.
        uint32_t targetHp     = 0;                 // сколько хп осталось у атакуемого
        bool     f_unitDied   = false;             // юнит мёртв.
        bool     f_activity   = false;             // была ли произведена атака.
    };

    // Пробуем атаковать ближайшего юнита.
    // DAMAGE_STAT - атрибут для просчёта урона
    // см. sw::entities::UnitAttributes
    MeleeAttackResult tryToRandomMeleeAttack(std::shared_ptr<GameField>&, Unit& attacker,
                                const UnitAttributes& DAMAGE_STAT);
}

#endif // MELEEATTACK_H
