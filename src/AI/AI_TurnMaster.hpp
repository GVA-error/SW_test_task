#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>

#include "Entities/UnitsHeap.hpp"
#include "Entities/GameField.hpp"
#include "Utils/MoveOrder.hpp"
#include "AI/Unit/AI_Unit.hpp"

namespace sw::AI
{
    // Отвечает за отработку AI юнитов во время хода
    using namespace sw::entities;
    class AI_TurnMaster
    {
    public:
        AI_TurnMaster(std::shared_ptr<UnitHeap>& uh, std::shared_ptr<utils::MoveOrder>& mo)
            : unitsHeap(uh), moveOrder(mo)
        {
        }
        virtual ~AI_TurnMaster() {};

        // Исполнение механик хода юнитами.
        // Возвращает было ли совершено какое либо действие.
        bool tick(uint32_t tickNumber);

        // Добавляем юниту мозгов. Пример вызова ai_TurnMaster->setUnitAI<AI::AI_Unit>(unitId, gameField);
        // AI_UNIT - наследник AI::AI_Unit.
        template <class UNIT_AI>
        void setUnitAI(uint32_t unitId, std::shared_ptr<GameField>& gf)
        {
            unitAI[unitId] = std::make_unique<UNIT_AI>(gf, unitsHeap);
        }

    private:
        std::shared_ptr<UnitHeap>                    unitsHeap;
        std::shared_ptr<utils::MoveOrder>            moveOrder;
        // искуственный интеллект юнита
        std::map<uint32_t, std::unique_ptr<AI_Unit>> unitAI;
        sw::EventLog eventLog;
        AI_TurnMaster() = delete;

        // .. юнитом
        bool tick(uint32_t unitId, uint32_t currentTick);
        bool tick(sw::entities::Unit&, uint32_t currentTick);
    };
}

