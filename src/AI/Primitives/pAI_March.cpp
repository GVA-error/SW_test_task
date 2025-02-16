#include "pAI_March.hpp"

#include "Mechanics/March.hpp"
#include "AI/Primitives/pAI_MarchLog.hpp"

namespace sw::AI::primitive
{
    bool pAI_tryToStep(std::shared_ptr<GameField>& gf, Unit& u,
                       uint32_t tickNumber, sw::EventLog& eventLog)
    {
        // пробуем сделать шаг.
        auto stepRes = mechanics::tryToNextStep(gf, u);
        pAI_MoveLog(u, stepRes, tickNumber, eventLog);
        return stepRes.f_activity;
    }
}
