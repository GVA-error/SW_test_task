#include "AI_General.hpp"

#include "AI/Primitives/pAI_March.hpp"

namespace sw::AI
{
    using namespace sw::entities;

    bool AI_General::MARCH(uint32_t tickNumber, std::shared_ptr<sw::entities::GameField>& gf,
                           uint32_t unitId, uint32_t targetX, uint32_t targetY)
    {
        FieldPos targetPos;
        targetPos.x = targetX;
        targetPos.y = targetY;
        return MARCH(tickNumber, gf, unitId, targetPos);
    }

    bool AI_General::MARCH(uint32_t tickNumber, std::shared_ptr<sw::entities::GameField>& gf,
                           uint32_t unitId, const FieldPos& targetPos)
    {
        auto& unit = unitHeap->unitById(unitId);
        return MARCH(tickNumber, gf, unit, targetPos);
    }

    bool AI_General::MARCH(uint32_t tickNumber, std::shared_ptr<sw::entities::GameField>& gf,
                           Unit& u, const FieldPos& targetPos)
    {

        auto w = gf->getWidth();
        auto h = gf->getHeight();

        auto unitPos = gf->getUnitPosition(u.getId());
        if (unitPos == utils::UNDEFINED_POSITION)
        {
            eventLog.log(tickNumber, sw::io::Error("Simulation::March field is not created. Use Simulation::CreateMap before."));
            return false;
        }

        bool f_outOfMap = false;
        f_outOfMap |= targetPos.x < 0;
        f_outOfMap |= targetPos.y < 0;
        f_outOfMap |= targetPos.x >= w;
        f_outOfMap |= targetPos.y >= h;

        if (f_outOfMap)
        {
            eventLog.log(tickNumber, sw::io::Error("Simulation::March incorrect position. Target is out of map."));
            return false;
        }

        bool f_activity = primitive::pAI_tryToStartMarch(gf, u, targetPos, tickNumber, eventLog);
        return f_activity;
    }
}
