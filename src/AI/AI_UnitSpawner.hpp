#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>

#include "Entities/UnitsHeap.hpp"
#include "Entities/GameField.hpp"
#include "Utils/MoveOrder.hpp"
#include "AI/Primitives/pAI_Spawn.hpp"

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
            bool f_activity = primitive::pAI_tryToSpawn(gf, unitsHeap, command, currentTick, eventLog);
            if (f_activity == false)
                return false;
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

