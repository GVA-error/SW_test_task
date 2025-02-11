#ifndef SPAWN_H
#define SPAWN_H

#include <memory>

#include "entities/Unit.h"
#include "IO/Commands/SpawnSwordsman.hpp"
#include "IO/Commands/SpawnHunter.hpp"
#include "entities/gamefield.h"

// Механики создания юнитов на игровом поле
// Отвечает за заполнение стат блока юнитов
namespace sw::mechanics
{
    using namespace sw::entities;

    // SpawnSwordsman
    Unit Spawn(std::shared_ptr<sw::entities::GameField>&, const sw::io::SpawnSwordsman&);

    // SpawnHunter
    Unit Spawn(std::shared_ptr<sw::entities::GameField>&, const sw::io::SpawnHunter&);

    // __base* - создание юнитов с предопределённым стат блоком
    // По умолчанию юнит занимает клетку на поле. UnitType::LAND_SOLID.
    template <class UnitSpawnCommand>
    Unit __baseUnit(std::shared_ptr<sw::entities::GameField>& gf, const UnitSpawnCommand& u, const std::string& name)
    {
        Unit unit(u.unitId, name);
        if (gf == nullptr)
        {
            unit.markAsIncorrect("can not spawn unit without field");
            return unit;
        }
        unit.set(UnitType::LAND_SOLID);
        auto f_success = gf->addUnit(unit, u.x, u.y);
        if (f_success == false)
        {
            unit.markAsIncorrect("can not add unit in this coordinates");
            return unit;
        }
        return unit;
    }

    // Подвижный юнит с хп
    template <class UnitSpawnCommand>
    Unit __baseLiveUnit(std::shared_ptr<sw::entities::GameField>& gf, const UnitSpawnCommand& u, const std::string& name)
    {
        auto unit = __baseUnit(gf, u, name);
        if (unit.isCorrect() == false)
            return unit;
        unit.set(UnitMechanic::MOVE);
        unit.set(UnitState::HP, u.hp);
        return unit;
    }

}

#endif // SPAWN_H
