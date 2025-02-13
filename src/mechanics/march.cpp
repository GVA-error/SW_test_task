#include "march.h"


namespace sw::mechanics
{

    MarchResult tryToNextStep(std::shared_ptr<sw::entities::GameField>& gf, sw::entities::Unit& u)
    {
        MarchResult res;
        if (u.isAllowed(UnitMechanic::MOVE) == false)
        {
            res.f_isMechanicAllowed = false;
            return res;
        }
        res.f_activity = gf->step(u);
        auto pos = gf->getUnitPosition(u);
        res.newX = pos.x;
        res.newY = pos.y;
        return res;
    }

}
