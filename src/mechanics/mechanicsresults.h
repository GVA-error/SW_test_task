#pragma once

#include <cstdint>
#include <string>

#include "utils/Coordinates.h"
#include "entities/UnitEnums.h"

// Структуры описывающие резуальтат использования механик.
namespace sw::mechanics
{
    using namespace sw::entities;

    // Минимальный результат для функционирования механик.
    struct BaseResult
    {
        bool     f_activity          = false;      // механика была воспроизведена.
        bool     f_isMechanicAllowed = true;       // механика не была запрещена намеренно.
    };

    // Результат достаточный для логирования описание атаки.
    struct DefaultAttackResult : BaseResult
    {
        uint32_t targetUnit   = UNDEFINED_UNIT_ID; // id юнита которого атаковали.
        uint32_t damage       = 0;                 // размер полученного урона.
        uint32_t targetHp     = 0;                 // сколько хп осталось у атакуемого
        bool     f_unitDied   = false;             // юнит мёртв.
    };

    // Результат достаточный для логирования описание шага марша.
    struct MarchResult : BaseResult
    {
        uint32_t newX         = utils::UNDEFINED_POSITION.x; // новая х - позиция
        uint32_t newY         = utils::UNDEFINED_POSITION.y; // .. y
        bool     f_marchEnded = false;                       // на этом тике мы пришли к финальной точке марша
        bool     f_activity   = false;                       // мы двигались или ждали такой возможности
    };

    // Результат достаточный для логирования описания создания.
    struct SpawnResult : BaseResult
    {
        bool f_isCorrect = false;         // Был ли создан юнит
        std::string  incorrectnessReason; // Причина ошибки, если она была
    };
}

