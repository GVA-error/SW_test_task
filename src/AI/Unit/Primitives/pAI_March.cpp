#include "pAI_March.hpp"

#include "Mechanics/March.hpp"
#include "AI/Unit/Primitives/pAI_MarchLog.hpp"

namespace sw::AI::primitive
{
    bool pAI_tryToStep(std::shared_ptr<GameField>& gf, Unit& u,
                       uint32_t tickNumber, sw::EventLog& eventLog)
    {
        // пробуем сделать шаг.
        auto stepRes = mechanics::tryToNextStep(gf, u);
        pAI_MoveLog(stepRes, tickNumber, eventLog);
        return stepRes.f_activity;
    }


    bool pAI_tryToStartMarch(std::shared_ptr<GameField>& gf, Unit& u, const FieldPos& targetPos,
                             uint32_t tickNumber, sw::EventLog& eventLog)
    {
        auto startRes = mechanics::tryToStartMarch(gf, u, targetPos);
        pAI_MarchStartLog(startRes, tickNumber, eventLog);
        return startRes.f_activity;
    }
}
