#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>

#include "entities/unitsheap.h"
#include "entities/gamefield.h"
#include "utils/MoveOrder.h"
#include "mechanics/Spawn.h"

namespace sw::AI
{
    // Создаёт юнитов на куче и поле. Добавляет их в очередь хода
    using namespace sw::entities;
    class AI_UnitSpawner
    {
    public:
        AI_UnitSpawner(std::shared_ptr<UnitHeap>& uh, std::shared_ptr<MoveOrder>& mo)
            : unitsHeap(uh), moveOrder(mo)
        {
        }
        virtual ~AI_UnitSpawner() {};

        template <class TCommand>
        bool spawn(std::shared_ptr<GameField>& gf, uint32_t currentTick, const TCommand& command)
        {
            if (unitsHeap->contains(command.unitId))
            {
                eventLog.log(currentTick, sw::io::Error("Simulation::spawnCommand trying to recreate unit with same id."));
                return false;
            }
            auto res = sw::mechanics::Spawn(gf, unitsHeap, command);
            if (res.f_isCorrect == false)
            {
                auto logMess = "Simulation::spawnCommand can not spawn by this command. Reason: " + res.incorrectnessReason;
                eventLog.log(currentTick, sw::io::Error(logMess));
                return false;
            }
            moveOrder->push(command.unitId);
            return true;
        }

    protected:
        std::shared_ptr<UnitHeap>  unitsHeap;
        std::shared_ptr<MoveOrder> moveOrder;
        sw::EventLog eventLog;
        AI_UnitSpawner() = delete;
    };
}

