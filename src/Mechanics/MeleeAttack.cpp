#include "MeleeAttack.hpp"

namespace sw::mechanics
{
    MeleeAttackResult tryToRandomMeleeAttack(std::shared_ptr<GameField>& gf, std::shared_ptr<UnitHeap>& uh, Unit& u,
                            const UnitAttributes& DAMAGE_STAT)
    {
        MeleeAttackResult res;
        if (u.isAllowed(UnitMechanic::MELEE_ATTACK) == false)
        {
            res.f_isMechanicAllowed = false;
            return res;
        }
        if (u.isDead())
            return res;

        // Ищем кого бы ударить
        auto targetId = gf->getRandomUnitInRadius(u, 1);

        // Не нашли
        if (targetId == UNDEFINED_UNIT_ID)
            return res;

        // Наносим урон от DAMAGE_STAT характеристики
        auto damage = u.getAttribute(DAMAGE_STAT);
        attack(u, targetId, gf, uh, damage, res);
        return res;
    }
}
