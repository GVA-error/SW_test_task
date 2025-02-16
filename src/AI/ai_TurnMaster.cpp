#include "ai_TurnMaster.h"


namespace sw::AI
{
    bool AI_TurnMaster::tick(uint32_t currentTick)
    {
        bool f_activityFound = false;
        if (moveOrder->size() == 0)
            return f_activityFound;
        const auto& turnQueue = moveOrder->getTurnQueue();
        for (auto curId : turnQueue)
        {
            bool f_unitActivity = tick(curId, currentTick);
            if (f_unitActivity)
                f_activityFound = true;
        }
        return f_activityFound;
    }

    bool AI_TurnMaster::tick(uint32_t unitId, uint32_t currentTick)
    {
        auto& u = unitsHeap->unitById(unitId);
        return tick(u, currentTick);
    }

    bool AI_TurnMaster::tick(sw::entities::Unit& u, uint32_t currentTick)
    {
        auto& AI = unitAI[u.getId()];
        bool f_activity = AI->tick(u, currentTick);
        return f_activity;
    }
}
