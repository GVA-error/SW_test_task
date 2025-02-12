#ifndef MARCH_H
#define MARCH_H

#include <memory>

#include "entities/gamefield.h"
#include "entities/Unit.h"

// Механики марша
namespace sw::mechanics
{
    using namespace sw::entities;

    struct MarchResult
    {
        uint32_t newX         = utils::UNDEFINED_POSITION.x;
        uint32_t newY         = utils::UNDEFINED_POSITION.y;
        bool     f_marchEnded = false;
        bool     f_activity   = false;
    };

    // Делаем следующий шаг на одну клетку к цели марша.
    MarchResult tryToNextStep(std::shared_ptr<sw::entities::GameField>&, sw::entities::Unit&);
}

#endif // MARCH_H
