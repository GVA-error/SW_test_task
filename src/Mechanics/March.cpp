#include "March.hpp"

namespace sw::mechanics
{
    MarchResult tryToNextStep(std::shared_ptr<sw::entities::GameField>& gf,
                          sw::entities::Unit& u)
    {
        MarchResult res;
        if (u.isAllowed(UnitMechanic::MOVE) == false)
        {
            res.f_isMechanicAllowed = false;
            return res;
        }
        res.f_activity        = gf->step(u);
        const auto& pos       = gf->getUnitPosition(u);
        const auto& targetPos = gf->getMarchTargetPos(u);
        res.f_marchEnded      = gf->onMarch(u) == false;
        res.newX    = pos.x;
        res.newY    = pos.y;
        res.targetX = targetPos.x;
        res.targetY = targetPos.y;
        res.unitId  = u.getId();
        return res;
    }

    MarchResult tryToStartMarch(std::shared_ptr<sw::entities::GameField>& gf,
                                sw::entities::Unit& u, const FieldPos& targetPos)
    {
        MarchResult res;
        if (u.isAllowed(UnitMechanic::MOVE) == false)
        {
            res.f_isMechanicAllowed = false;
            return res;
        }
        gf->March(u.getId(), targetPos.x, targetPos.y);
        res.f_activity = gf->onMarch(u);
        const auto& target = gf->getMarchTargetPos(u);
        auto unitPos = gf->getUnitPosition(u.getId());
        res.targetX = target.x;
        res.targetY = target.y;
        res.newX    = unitPos.x;
        res.newY    = unitPos.y;
        res.unitId  = u.getId();
        return res;
    }
}
