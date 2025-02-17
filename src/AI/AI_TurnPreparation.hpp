#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>

#include "Entities/UnitsHeap.hpp"
#include "Entities/GameField.hpp"
#include "Utils/MoveOrder.hpp"

namespace sw::AI
{
    // Отвечает за события начала и конца хода
    // Подготавливает поле к событиям хода
    using namespace sw::entities;
    class AI_TurnPraparation
    {
    public:
        AI_TurnPraparation(std::shared_ptr<UnitHeap>& uh, std::shared_ptr<MoveOrder>& mo)
            : unitsHeap(uh), moveOrder(mo)
        {
        }
        virtual ~AI_TurnPraparation() {};

        void turnPreparation(std::shared_ptr<GameField>&);
        void turnPostHandle(std::shared_ptr<GameField>&);

    protected:
        std::shared_ptr<UnitHeap>  unitsHeap;
        std::shared_ptr<MoveOrder> moveOrder;
        sw::EventLog eventLog;
        AI_TurnPraparation() = delete;
    };
}

