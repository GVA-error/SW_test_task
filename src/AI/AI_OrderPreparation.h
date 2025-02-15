#ifndef AI_ORDERPREPARATION_H
#define AI_ORDERPREPARATION_H

#include <memory>
#include "entities/gamefield.h"
#include "entities/unitsheap.h"
#include "utils/MoveOrder.h"
#include "IO/System/EventLog.hpp"

namespace sw::AI
{
    // Отвечает за события начала и конца хода
    // Подготавливает поле к событиям хода
    using namespace sw::entities;
    class AI_OrderPraparation
    {
    public:
        AI_OrderPraparation(std::shared_ptr<UnitHeap>& uh, std::shared_ptr<MoveOrder>& mo)
            : unitsHeap(uh), moveOrder(mo)
        {
        }
        virtual ~AI_OrderPraparation() {};

        void orderPreparation(std::shared_ptr<GameField>&);
        void orderPostHandle(std::shared_ptr<GameField>&);

    protected:
        std::shared_ptr<UnitHeap>  unitsHeap;
        std::shared_ptr<MoveOrder> moveOrder;
        sw::EventLog eventLog;
        AI_OrderPraparation() = delete;
    };
}


#endif // AI_ORDERPREPARATION_H
