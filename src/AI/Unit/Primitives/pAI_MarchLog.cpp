#include "pAI_MarchLog.hpp"

#include <IO/Events/MarchStarted.hpp>
#include <IO/Events/MarchEnded.hpp>
#include <IO/Events/UnitMoved.hpp>

namespace sw::AI::primitive
{
    void pAI_MoveLog(mechanics::MarchResult& moveRes, uint32_t tickNumber, sw::EventLog& eventLog)
    {
        // Выводим лог только если юнит двигался или ждал.
        // Для детектирования использования механики шага, выводим шаг, даже если уже на финальной точке марша
        if (moveRes.f_activity)
        {
            sw::io::UnitMoved moveEvent;
            moveEvent.unitId = moveRes.unitId;
            moveEvent.x      = moveRes.newX;
            moveEvent.y      = moveRes.newY;
            eventLog.log(tickNumber, std::move(moveEvent));

            // Это был последний шаг марша
            if (moveRes.f_marchEnded)
            {
                sw::io::MarchEnded marchEndedEvent;
                marchEndedEvent.unitId = moveRes.unitId;
                marchEndedEvent.x      = moveRes.newX;
                marchEndedEvent.y      = moveRes.newY;
                eventLog.log(tickNumber, std::move(marchEndedEvent));
            }
        }
    }

    void pAI_MarchStartLog(mechanics::MarchResult& startRes, uint32_t tickNumber, sw::EventLog& eventLog)
    {
        if (startRes.f_activity)
        {
            io::MarchStarted marchStartedEvent;
            marchStartedEvent.targetX = startRes.targetX;
            marchStartedEvent.targetY = startRes.targetY;
            marchStartedEvent.x       = startRes.newX;
            marchStartedEvent.y       = startRes.newY;
            marchStartedEvent.unitId  = startRes.unitId;
            eventLog.log(tickNumber, std::move(marchStartedEvent));
        }
    }
}
