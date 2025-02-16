#pragma once
#include <cstdint>

#include "Utils/Coordinates.hpp"
#include "BaseResult.hpp"

namespace sw::mechanics
{
    // Результат достаточный для логирования шага марша.
    struct MarchResult : BaseResult
    {
        uint32_t newX         = utils::UNDEFINED_POSITION.x; // новая х - позиция
        uint32_t newY         = utils::UNDEFINED_POSITION.y; // .. y
        bool     f_marchEnded = false;                       // на этом тике мы пришли к финальной точке марша
    };
}
