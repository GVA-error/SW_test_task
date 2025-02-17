#include "AI_General.hpp"

#include "AI/Unit/Primitives/pAI_March.hpp"

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
        // Отдать приказ не существующему юниту не возможно
        if (unitHeap->contains(unitId) == false)
        {
            eventLog.log(tickNumber, sw::io::Error("Simulation::March field unit is not exists."));
            return false;
        }
        auto& unit = unitHeap->unitById(unitId);
        return MARCH(tickNumber, gf, unit, targetPos);
    }

    bool AI_General::MARCH(uint32_t tickNumber, std::shared_ptr<sw::entities::GameField>& gf,
                           Unit& u, const FieldPos& targetPos)
    {
        auto unitPos = gf->getUnitPosition(u.getId());
        if (unitPos == utils::UNDEFINED_POSITION)
        {
            eventLog.log(tickNumber, sw::io::Error("Simulation::March field is not created. Use Simulation::CreateMap before."));
            return false;
        }
        if (gf->isOutOfField(targetPos))
        {
            eventLog.log(tickNumber, sw::io::Error("Simulation::March incorrect position. Target is out of map."));
            return false;
        }

        bool f_activity = primitive::pAI_tryToStartMarch(gf, u, targetPos, tickNumber, eventLog);
        return f_activity;
    }
}
