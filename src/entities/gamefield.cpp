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
        if (unitsOnPosition[unitPos].size() == 0) // Чтобы от шагов не росло потребление памяти.
            unitsOnPosition.erase(unitPos);
        bool f_activity = unitPaths.step(id, landObstacle, unitPos, width, height);
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

    bool GameField::isDead(uint32_t unitId) const
    {
        return deadSet.find(unitId) != deadSet.end();
    }

    bool GameField::onMarch(const sw::entities::Unit& u) const
    {
        return unitPaths.haveTarget(u.getId());
    }

    std::list<uint32_t> GameField::getUnitsInRadius(const Unit& u, uint32_t radius, bool f_liveOnly) const
    {
        return getUnitsInRadius(u.getId(), radius, f_liveOnly);
    }

    std::list<uint32_t> GameField::getUnitsInRadius(uint32_t unitId, uint32_t radius, bool f_liveOnly) const
    {
        return getUnitsInRadius(getUnitPosition(unitId), radius, f_liveOnly);
    }

    uint32_t GameField::findRandomLiveUnitInPos(uint32_t x, uint32_t y) const
    {
        FieldPos p;
        p.x = x;
        p.y = y;
        if (unitsOnPosition.find(p) == unitsOnPosition.end())
            return UNDEFINED_UNIT_ID;
        int32_t unitsNumber = unitsOnPosition.at(p).size();
        if (unitsNumber == 0)
            return UNDEFINED_UNIT_ID;
        // берём случайного
        auto c = utils::randomChoice(unitsOnPosition.at(p));
        // Если он мёртв, то просто ищем первого живого
        if (isDead(c))
        {
            c = UNDEFINED_UNIT_ID;
            for (auto unitId : unitsOnPosition.at(p))
                if (isDead(unitId) == false)
                    return unitId;
        }
        return c;
    }

    std::list<uint32_t> GameField::getUnitsInRadius(const FieldPos& p, uint32_t radius, bool f_liveOnly) const
    {
        std::list<uint32_t> res;
        for (int32_t x = p.x-radius; x<=p.x+radius; x++)
            for (int32_t y = p.y-radius; y<=p.y+radius; y++)
            {
                if (x < 0 || y < 0)
                    continue;
                if (x == p.x && y == p.y)
                    continue;
                auto distanceValue = utils::distance(p, x, y);
                if (distanceValue <= radius)
                {
                    auto randomUnitId = findRandomLiveUnitInPos(x, y);
                    if (randomUnitId == UNDEFINED_UNIT_ID)
                        continue;
                    res.push_back(randomUnitId);
                }
            }
        return res;
    }

    uint32_t GameField::getRandomUnitInRadius(const Unit& u, uint32_t radius, bool f_liveOnly) const
    {
        auto candidates = getUnitsInRadius(u, radius, f_liveOnly);
        if (candidates.size() == 0)
            return UNDEFINED_UNIT_ID;

        // берём случайного
        return utils::randomChoice(candidates);
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
