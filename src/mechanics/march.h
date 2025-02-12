#ifndef MARCH_H
#define MARCH_H

#include <memory>

#include "entities/gamefield.h"
#include "entities/Unit.h"
#include "mechanics/mechanicsresults.h"

// Механики марша
namespace sw::mechanics
{
    using namespace sw::entities;

    // Делаем следующий шаг на одну клетку к цели марша.
    MarchResult tryToNextStep(std::shared_ptr<sw::entities::GameField>&, sw::entities::Unit&);
}

#endif // MARCH_H
