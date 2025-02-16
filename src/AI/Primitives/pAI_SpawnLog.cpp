#include "pAI_SpawnLog.hpp"

#include "IO/Events/UnitSpawned.hpp"

namespace sw::AI::primitive
{
    void pAI_SpawnLog(mechanics::SpawnResult& res, uint32_t tickNumber, sw::EventLog& eventLog)
    {
        if (res.f_isCorrect == false)
        {
            auto logMess = "Simulation::spawnCommand can not spawn by this command. Reason: " + res.incorrectnessReason;
            eventLog.log(tickNumber, sw::io::Error(logMess));
        }
        else
        {
            sw::io::UnitSpawned unitSpawnedEvent;
            unitSpawnedEvent.unitId   = res.unitId;
            unitSpawnedEvent.unitType = res.unitType;
            unitSpawnedEvent.x        = res.x;
            unitSpawnedEvent.y        = res.y;
            eventLog.log(tickNumber, std::move(unitSpawnedEvent));
        }
    }
}
