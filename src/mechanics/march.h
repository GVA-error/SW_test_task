#pragma once

#include <memory>

#include "entities/Unit.h"
#include "entities/gamefield.h"
#include "mechanics/mechanicsresults.h"

// Механики марша
namespace sw::mechanics
{
    using namespace sw::entities;

    // Делаем следующий шаг на одну клетку к цели марша.
    MarchResult tryToNextStep(std::shared_ptr<sw::entities::GameField>&, sw::entities::Unit&);
}

