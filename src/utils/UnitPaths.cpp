#include "UnitPaths.h"
#include <climits>


namespace sw::utils
{
    UnitPaths::UnitPaths() {}

    void UnitPaths::setUnitTarget(uint32_t id, const FieldPos& pos)
    {
        target[id] = pos;
    }

    void UnitPaths::setUnitTarget(uint32_t id, uint32_t x, uint32_t y)
    {
        setUnitTarget(id, {x, y});
    }

    bool UnitPaths::step(uint32_t id, FieldPos& unitPos)
    {
        return step(id, {}, unitPos);
    }

    bool UnitPaths::step(uint32_t id, const std::set<FieldPos>& landObstacle,
              FieldPos& unitPos)
    {
        // В данный момент любое поведение данной функции при наличии цели марша является активностью
        // так как все препятствия динамические.
        if (target.find(id) == target.end())
            return false;
        bool f_activity = true;
        auto targetPos  = target[id];
        auto candidates       = getAllowedMovePosition(unitPos);
        FieldPos bestChoice   = unitPos; // если не найдём лучше, остаёмься на месте
        uint32_t bestDistance = UINT_MAX;
        for (const auto& c : candidates)
        {
            if (landObstacle.find(c) != landObstacle.end())
                continue;
            auto curDist = distance(targetPos, c);
            if (curDist == bestDistance)
            {
                // Делаем движение чуть более естественным.
                if (rand()%2)
                    bestChoice = c;
            }
            else if (curDist < bestDistance)
            {
                bestChoice = c;
                bestDistance = curDist;
            }

        }
        unitPos = bestChoice;
        // Если достигли цели, то прекращаем к ней стремится.
        if (unitPos == targetPos)
            target.erase(id);
        return f_activity;
    }

    bool UnitPaths::haveTarget(uint32_t id) const
    {
        return target.find(id) != target.end();
    }

}

