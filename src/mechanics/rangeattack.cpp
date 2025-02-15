#include "rangeattack.h"
#include "mechanics/attack.h"

namespace sw::mechanics
{
    using namespace sw::entities;
    RangeAttackResult tryToRandomRangeAttack(std::shared_ptr<sw::entities::GameField>& gf, std::shared_ptr<UnitHeap>& uh,
                                             sw::entities::Unit& u, const UnitAttributes& DAMAGE_STAT)
    {
        RangeAttackResult res;
        if (u.isAllowed(UnitMechanic::RANGE_ATTACK) == false)
        {
            res.f_isMechanicAllowed = false;
            return res;
        }
        if (u.isDead())
            return res;

        // Ищем кого бы ударить
        auto range    = u.getAttribute(UnitAttributes::Range);
        auto targetId = gf->getRandomUnitInRadius(u, range);

        // Не нашли
        if (targetId == UNDEFINED_UNIT_ID)
            return res;

        // Наносим урон от DAMAGE_STAT характеристики
        auto damage = u.getAttribute(DAMAGE_STAT);
        attack(u, targetId, gf, uh, damage, res);
        return res;
    }
}
