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


        return res;
    }

}
