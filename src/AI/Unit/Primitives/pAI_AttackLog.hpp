#pragma once

#include <IO/System/EventLog.hpp>
#include <IO/System/EventLog.hpp>
#include <IO/Events/UnitAttacked.hpp>
#include <IO/Events/UnitDied.hpp>

// вывод лога для атак
namespace sw::AI::primitive
{
    template <class ATTACK_RES_TYPE>
    void pAI_AttackLog(const ATTACK_RES_TYPE& attackRes,
                       uint32_t tickNumber, sw::EventLog& eventLog)
    {
        // Выводим лог только если атака была произведена
        if (attackRes.f_activity)
        {
            sw::io::UnitAttacked unitAttackedEvent;
            unitAttackedEvent.attackerUnitId = attackRes.attackerUnit;
            unitAttackedEvent.targetUnitId   = attackRes.targetUnit;
            unitAttackedEvent.targetHp       = attackRes.targetHp;
            unitAttackedEvent.damage         = attackRes.damage;
            eventLog.log(tickNumber, std::move(unitAttackedEvent));
            if (attackRes.f_unitDied)
            {
                sw::io::UnitDied unitDiedEvent;
                unitDiedEvent.unitId = attackRes.targetUnit;
                eventLog.log(tickNumber, std::move(unitDiedEvent));
            }
        }
    }
}

