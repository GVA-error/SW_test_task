#pragma once

#include <memory>

#include "Entities/Unit.hpp"
#include "Entities/GameField.hpp"
#include "Mechanics/MechanicsResult/MarchResult.hpp"

// Механики марша
namespace sw::mechanics
{
    using namespace sw::entities;

    // Делаем следующий шаг на одну клетку к цели марша.
    MarchResult tryToNextStep(std::shared_ptr<sw::entities::GameField>&, sw::entities::Unit&);

    MarchResult tryToStartMarch(std::shared_ptr<sw::entities::GameField>&, sw::entities::Unit&, const FieldPos&);
}

