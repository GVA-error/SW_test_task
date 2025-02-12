#include "meleeattack.h"


namespace sw::mechanics
{
    MeleeAttackResult tryToRandomMeleeAttack(std::shared_ptr<GameField>& gf, Unit& u,
                            const UnitAttributes& DAMAGE_STAT)
    {
        MeleeAttackResult res;
        if (u.isAllowed(UnitMechanic::MELEE_ATTACK) == false)
        {
            res.f_isMechanicAllowed = false;
            return res;
        }

        return res;
    }
}
