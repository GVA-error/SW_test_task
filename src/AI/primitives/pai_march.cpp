#include "pai_march.h"

#include "mechanics/march.h"
#include "AI/primitives/pAI_MarchLog.h"

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
