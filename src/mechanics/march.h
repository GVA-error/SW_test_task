#ifndef MARCH_H
#define MARCH_H

#include <memory>

#include "entities/gamefield.h"
#include "entities/Unit.h"

// Механики марша
namespace sw::mechanics
{
    // Делаем следующий шаг к цели марша.
    // Если юнит ждал или сделал шаг возвращает true
    bool tryToNextStep(std::shared_ptr<sw::entities::GameField>&, sw::entities::Unit&);
}

#endif // MARCH_H
