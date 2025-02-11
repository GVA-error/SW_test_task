#include "gamefield.h"


namespace sw::entities
{

    GameField::GameField(uint32_t w, uint32_t h)
    {
        width = w;
        height = h;
    }

    uint32_t GameField::getWidth()  const
    {
        return width;
    }

    uint32_t GameField::getHeight() const
    {
        return height;
    }

    sw::utils::FieldPos GameField::getUnitPosition(uint32_t unitId) const
    {
        if (unitPosition.find(unitId) == unitPosition.end())
            return utils::UNDEFINED_POSITION;
        return unitPosition.at(unitId);
    }

    void GameField::March(uint32_t unitId, uint32_t targetX, uint32_t targetY)
    {
        unitPaths.setUnitTarget(unitId, targetX, targetY);
    }

    bool GameField::addUnit(sw::entities::Unit& unit, uint32_t x, uint32_t y)
    {
        auto id = unit.getId();
        utils::FieldPos pos({x, y});
        auto f_solid = unit.is(UnitType::LAND_SOLID);
        if (f_solid)
        {
            if (landObstacle[pos])
                return false;
            landObstacle[pos] = true;
        }

        unitIsLandObstacle[id] = f_solid;
        unitsOnPosition[pos].insert(id);
        unitPosition[id] = pos;
    }

}
