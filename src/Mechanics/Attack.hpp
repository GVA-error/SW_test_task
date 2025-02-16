#pragma once

#include <memory>

#include "Entities/UnitsHeap.hpp"
#include "Entities/Unit.hpp"
#include "Entities/GameField.hpp"

// Общая механика атаки - нанесение одним юнитом урона другому.
// С возможностью смерти
namespace sw::mechanics
{
    using namespace sw::entities;

    template <class ATTACK_RESULT>
    void attack(Unit& attacker, Unit& target, std::shared_ptr<GameField>& gf, uint32_t damage, ATTACK_RESULT& res)
    {
        if (attacker.isDead())
            return;
        target.takeDamage(damage);
        if (target.isDead())
            gf->kill(target.getId()); // Синхронизируем юнита с его "телом"

        res.f_activity = true;
        // Описываем, что произошло
        res.targetUnit = target.getId();
        res.damage     = damage;
        res.targetHp   = target.getCurrentHP();
        res.f_unitDied = target.isDead();
    }

    template <class ATTACK_RESULT>
    void attack(Unit& attacker, uint32_t targetUnitId, std::shared_ptr<GameField>& gf, std::shared_ptr<UnitHeap>& uh, uint32_t damage, ATTACK_RESULT& res)
    {
        auto& target = uh->unitById(targetUnitId);
        attack(attacker, target, gf, damage, res);
    }
}

