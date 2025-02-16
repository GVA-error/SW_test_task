#pragma once
#include <cstdint>

#include "Entities/UnitEnums.hpp"
#include "Utils/Coordinates.hpp"
#include "BaseResult.hpp"

namespace sw::mechanics
{
    // Результат достаточный для логирования шага марша.
    struct MarchResult : BaseResult
    {
        uint32_t unitId       = entities::UNDEFINED_UNIT_ID;

        uint32_t newX         = utils::UNDEFINED_POSITION.x; // текущая х - позиция
        uint32_t newY         = utils::UNDEFINED_POSITION.y; // .. y
        bool     f_marchEnded = false;                       // на этом тике мы пришли к финальной точке марша

        uint32_t targetX      = utils::UNDEFINED_POSITION.x; // х - позиция точки цели
        uint32_t targetY      = utils::UNDEFINED_POSITION.y; // .. y
    };
}
