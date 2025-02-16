#pragma once

#include <string>

#include "BaseResult.hpp"

namespace sw::mechanics
{
    // Результат достаточный для логирования описания создания юнита.
    struct SpawnResult : BaseResult
    {
        bool f_isCorrect = false;         // Был ли создан юнит
        std::string  incorrectnessReason; // Причина ошибки, если она была
    };
}
