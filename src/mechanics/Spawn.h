#ifndef SPAWN_H
#define SPAWN_H

#include <memory>

#include "entities/Unit.h"
#include "IO/Commands/SpawnSwordsman.hpp"
#include "IO/Commands/SpawnHunter.hpp"
#include "entities/gamefield.h"

// Механики создания юнитов
namespace sw::mechanics::spawn
{
    using namespace sw::entities;

    template <class UnitSpawnCommand>
    Unit baseLiveUnit(std::shared_ptr<sw::entities::GameField>& gf, const UnitSpawnCommand& u, const std::string& name)
    {
        Unit unit(u.unitId, name);
        unit.set(UnitState::HP, u.hp);
        unit.set(UnitMechanic::MOVE);
        auto f_success = gf->addUnit(unit, u.x, u.y);
        if (f_success == false)
            unit.markAsIncorrect();
        return unit;
    }

    // SpawnSwordsman
    Unit Spawn(std::shared_ptr<sw::entities::GameField>&, const sw::io::SpawnSwordsman&);

    // SpawnHunter
    Unit Spawn(std::shared_ptr<sw::entities::GameField>&, const sw::io::SpawnHunter&);

}

#endif // SPAWN_H
