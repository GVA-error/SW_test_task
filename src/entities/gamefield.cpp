#include "gamefield.h"

namespace sw::entities
{
    using namespace std;
    using namespace sw::utils;
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

    FieldPos GameField::getUnitPosition(const sw::entities::Unit& u) const
    {
        return getUnitPosition(u.getId());
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
            if (landObstacle.find(pos) != landObstacle.end())
                return false;
            landObstacle.insert(pos);
        }

        unitIsLandObstacle[id] = f_solid;
        unitsOnPosition[pos].insert(id);
        unitPosition[id] = pos;
        return true;
    }


    bool GameField::step(sw::entities::Unit& u)
    {
        auto id = u.getId();
        auto& unitPos = unitPosition[id];

        // Двигаем юнита
        if (unitIsLandObstacle[id])
            landObstacle.erase(unitPos);
        unitsOnPosition[unitPos].erase(id);
        bool f_activity = unitPaths.step(id, landObstacle, unitPos);
        unitsOnPosition[unitPos].insert(id);
        landObstacle.insert(unitPos);

        return f_activity;
    }

    void GameField::kill(uint32_t unitId)
    {
        deadSet.insert(unitId);
        if (unitIsLandObstacle[unitId])
        {
            const auto& unitPos = unitPosition[unitId];
            landObstacle.erase(unitPos);
            unitIsLandObstacle[unitId] = false;
        }
    }

    bool GameField::onMarch(const sw::entities::Unit& u) const
    {
        return unitPaths.haveTarget(u.getId());
    }


    std::list<uint32_t> GameField::getUnitsInRadius(const FieldPos& p, uint32_t radius) const
    {
        std::list<uint32_t> res;
        assert(false);
        return res;
    }

    uint32_t GameField::deadSetSize() const
    {
        return deadSet.size();
    }

    void GameField::eraseDeadUnits()
    {
        assert(false);
    }

    void deleteUnit(uint32_t unitId)
    {
        assert(false);
    }

}
