#include "rangeattack.h"


namespace sw::mechanics
{
    using namespace sw::entities;
    RangeAttackResult tryToRandomRangeAttack(std::shared_ptr<sw::entities::GameField>& gf, sw::entities::Unit& u,
                            const UnitAttributes& DAMAGE_STAT)
    {
        RangeAttackResult res;
        if (u.isAllowed(UnitMechanic::RANGE_ATTACK) == false)
        {
            res.f_isMechanicAllowed = false;
            return res;
        }

        return res;
    }
}
