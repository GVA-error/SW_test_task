#include "UnitPaths.h"


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

    bool UnitPaths::step(uint32_t id, const std::map<FieldPos, bool>& landObstacle,
              FieldPos& unitPos)
    {
        unitPos.x++;

        return true;
    }

    bool UnitPaths::haveTarget(uint32_t id) const
    {
        return target.find(id) != target.end();
    }

}

