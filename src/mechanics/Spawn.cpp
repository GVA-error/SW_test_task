#include "Spawn.h"

namespace sw::mechanics
{
    using namespace sw::entities;
    // Создание юнита представляет из себя заполнение его стат блока

    Unit Spawn(std::shared_ptr<sw::entities::GameField>& gf, const sw::io::SpawnSwordsman& sm)
    {
        auto unit = __baseLiveUnit(gf, sm, "SpawnSwordsman");

        unit.set(UnitAttributes::Strength, sm.strength);

        unit.set(UnitMechanic::MELEE_ATTACK);

        return unit;
    }

    Unit Spawn(std::shared_ptr<sw::entities::GameField>& gf, const sw::io::SpawnHunter& h)
    {
        auto unit = __baseLiveUnit(gf, h, "SpawnHunter");

        if (h.range < 2)
        {
            unit.markAsIncorrect("we try SpawnHunter with small range");
            return unit;
        }

        unit.set(UnitAttributes::Strength, h.strength);
        unit.set(UnitAttributes::Agility,  h.agility);
        unit.set(UnitAttributes::Range,    h.range);

        unit.set(UnitMechanic::MELEE_ATTACK);
        unit.set(UnitMechanic::RANGE_ATTACK);

        return unit;
    }

}
