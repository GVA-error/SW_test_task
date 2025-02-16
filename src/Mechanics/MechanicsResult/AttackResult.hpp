#pragma once
#include <cstdint>

#include "Entities/UnitEnums.hpp"
#include "BaseResult.hpp"

namespace sw::mechanics
{

    // Результат достаточный для логирования описания атаки.
    struct AttackResult : BaseResult
    {
        uint32_t targetUnit   = entities::UNDEFINED_UNIT_ID; // id юнита которого атаковали.
        uint32_t damage       = 0;                           // размер полученного урона.
        uint32_t targetHp     = 0;                           // сколько хп осталось у атакуемого
        bool     f_unitDied   = false;                       // юнит мёртв.
    };

}
