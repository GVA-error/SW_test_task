#pragma once

#include <memory>

#include <IO/Commands/SpawnSwordsman.hpp>
#include <IO/Commands/SpawnHunter.hpp>

#include "Entities/UnitsHeap.hpp"
#include "Entities/GameField.hpp"
#include "Mechanics/MechanicsResult/SpawnResult.hpp"

// Механики создания юнитов на игровом поле
// Отвечает за заполнение стат блока юнитов
namespace sw::mechanics
{
    using namespace sw::entities;

    // SpawnSwordsman
    SpawnResult Spawn(std::shared_ptr<GameField>&, std::shared_ptr<UnitHeap>&, const sw::io::SpawnSwordsman&);

    // SpawnHunter
    SpawnResult Spawn(std::shared_ptr<GameField>&, std::shared_ptr<UnitHeap>&, const sw::io::SpawnHunter&);

    // __base* - создание юнитов с предопределённым стат блоком
    // По умолчанию юнит занимает клетку на поле. UnitType::LAND_SOLID.
    template <class UnitSpawnCommand>
    SpawnResult __baseUnit(std::shared_ptr<sw::entities::GameField>& gf, std::shared_ptr<UnitHeap>& uh,
                           const UnitSpawnCommand& u, const std::string& name)
    {
        SpawnResult res;
        if (gf == nullptr)
        {
            res.incorrectnessReason = "Can not spawn unit without field";
            return res;
        }
        if (gf->isOutOfField(u.x, u.y))
        {
            res.incorrectnessReason = "Can not spawn unit out off field";
            return res;
        }
        uh->add(u.unitId, name);
        auto& unit = uh->unitById(u.unitId);
        unit.set(UnitType::LAND_SOLID);
        auto f_success = gf->addUnit(unit, u.x, u.y);
        if (f_success == false)
        {
            res.incorrectnessReason = "can not add unit in this coordinates";
            uh->erase(u.unitId);
            return res;
        }

        res.f_isCorrect = true;

        res.unitId   = unit.getId();
        res.unitType = unit.getName();
        auto unitPos = gf->getUnitPosition(unit.getId());
        res.x        = unitPos.x;
        res.y        = unitPos.y;

        return res;
    }

    // Подвижный юнит с хп
    template <class UnitSpawnCommand>
    SpawnResult __baseLiveUnit(std::shared_ptr<sw::entities::GameField>& gf, std::shared_ptr<UnitHeap>& uh,
                               const UnitSpawnCommand& u, const std::string& name)
    {
        auto res = __baseUnit(gf, uh, u, name);
        if (res.f_isCorrect == false)
            return res;
        auto& unit = uh->unitById(u.unitId);
        unit.set(UnitMechanic::MOVE);
        unit.set(UnitStatus::HP, u.hp);
        // Спаун мертвеца
        if (unit.isDead())
            gf->kill(unit.getId());
        return res;
    }

}

