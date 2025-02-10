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

}

