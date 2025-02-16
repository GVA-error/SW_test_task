#pragma once

#include <string>
#include <cstdint>

#include "BaseResult.hpp"

namespace sw::mechanics
{
    // Результат достаточный для логирования создания юнита.
    struct SpawnResult : BaseResult
    {
        bool f_isCorrect = false;         // Был ли создан юнит
        std::string  incorrectnessReason; // Причина ошибки, если она была

        uint32_t    unitId;
        std::string unitType;
        uint32_t    x;
        uint32_t    y;
    };
}
