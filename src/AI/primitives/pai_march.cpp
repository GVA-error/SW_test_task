#include "pai_march.h"

#include "mechanics/march.h"
#include "IO/Events/UnitMoved.hpp"
#include "IO/Events/MarchEnded.hpp"

namespace sw::AI::primitive
{
    bool pAI_tryToStep(std::shared_ptr<GameField>& gf, Unit& u,
                       uint32_t tickNumber, sw::EventLog& eventLog)
    {
        // пробуем сделать шаг.
        auto stepRes = mechanics::tryToNextStep(gf, u);

        // Удалось сделать шаг
        if (stepRes.f_activity)
        {
            sw::io::UnitMoved moveEvent;
            moveEvent.unitId = u.getId();
            moveEvent.x      = stepRes.newX;
            moveEvent.y      = stepRes.newY;
            eventLog.log(tickNumber, std::move(moveEvent));

            // Это был последний шаг марша
            if (stepRes.f_marchEnded)
            {
                sw::io::MarchEnded marchEndedEvent;
                marchEndedEvent.unitId = u.getId();
                marchEndedEvent.x      = stepRes.newX;
                marchEndedEvent.y      = stepRes.newY;
                eventLog.log(tickNumber, std::move(marchEndedEvent));
            }
            return true;
        }
        return false;
    }
}
