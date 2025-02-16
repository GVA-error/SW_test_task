#include "pAI_MarchLog.hpp"

#include <IO/Events/MarchEnded.hpp>
#include <IO/Events/UnitMoved.hpp>

namespace sw::AI::primitive
{
    void pAI_MoveLog(const Unit& u, mechanics::MarchResult& moveRes, uint32_t tickNumber, sw::EventLog& eventLog)
    {
        // Выводим лог только если атака была произведена
        if (moveRes.f_activity)
        {
            // Удалось сделать шаг
            if (moveRes.f_activity)
            {
                sw::io::UnitMoved moveEvent;
                moveEvent.unitId = u.getId();
                moveEvent.x      = moveRes.newX;
                moveEvent.y      = moveRes.newY;
                eventLog.log(tickNumber, std::move(moveEvent));

                // Это был последний шаг марша
                if (moveRes.f_marchEnded)
                {
                    sw::io::MarchEnded marchEndedEvent;
                    marchEndedEvent.unitId = u.getId();
                    marchEndedEvent.x      = moveRes.newX;
                    marchEndedEvent.y      = moveRes.newY;
                    eventLog.log(tickNumber, std::move(marchEndedEvent));
                }
            }
        }
    }
}
