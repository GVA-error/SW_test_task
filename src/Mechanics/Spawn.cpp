#include "Spawn.hpp"

namespace sw::mechanics
{
    using namespace sw::entities;
    // Создание юнита представляет из себя заполнение его стат блока

    SpawnResult Spawn(std::shared_ptr<sw::entities::GameField>& gf, std::shared_ptr<UnitHeap>& uh,
                      const sw::io::SpawnSwordsman& sm)
    {
        auto res = __baseLiveUnit(gf, uh, sm, "SpawnSwordsman");
        if (res.f_isCorrect == false)
            return res;

        Unit& unit = uh->unitById(sm.unitId);

        unit.set(UnitAttributes::Strength, sm.strength);

        unit.set(UnitMechanic::MELEE_ATTACK);

        return res;
    }

    SpawnResult Spawn(std::shared_ptr<sw::entities::GameField>& gf, std::shared_ptr<UnitHeap>& uh,
                      const sw::io::SpawnHunter& h)
    {
        if (h.range < 2)
        {
            SpawnResult res;
            res.incorrectnessReason = "we try to SpawnHunter with small range";
            return res;
        }
        auto res = __baseLiveUnit(gf, uh, h, "SpawnHunter");
        if (res.f_isCorrect == false)
            return res;

        auto& unit = uh->unitById(h.unitId);

        unit.set(UnitAttributes::Strength, h.strength);
        unit.set(UnitAttributes::Agility,  h.agility);
        unit.set(UnitAttributes::Range,    h.range);

        unit.set(UnitMechanic::MELEE_ATTACK);
        unit.set(UnitMechanic::RANGE_ATTACK);

        return res;
    }

}
