#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>

#include "Entities/Unit.hpp"
#include "Entities/UnitsHeap.hpp"
#include "Entities/GameField.hpp"

namespace sw::AI
{
    using namespace sw::entities;
    // Раздаёт команды юнитам
    // "Пойди туда - сделай это"
    class AI_General
    {
    public:
        AI_General(std::shared_ptr<UnitHeap>& uh)
            : unitHeap(uh)
        {
        }
        virtual ~AI_General() {};

        bool MARCH(uint32_t tickNumber, std::shared_ptr<sw::entities::GameField>&, Unit&, const FieldPos&);
        bool MARCH(uint32_t tickNumber, std::shared_ptr<sw::entities::GameField>&, uint32_t unitId, const FieldPos&);
        bool MARCH(uint32_t tickNumber, std::shared_ptr<sw::entities::GameField>&, uint32_t unitId, uint32_t targetX, uint32_t targetY);

    private:
        std::shared_ptr<UnitHeap>  unitHeap;
        sw::EventLog eventLog;
    };
}

