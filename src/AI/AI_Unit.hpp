#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>

#include "Entities/UnitsHeap.hpp"
#include "Entities/Unit.hpp"
#include "Entities/GameField.hpp"

namespace sw::AI
{
    using namespace sw::entities;
    class AI
    {
    public:
        virtual ~AI() {};

        // Описываем, что юнит делает во время хода
        // Возвращает был ли юнит активен во время хода
        // Ожидание считаем активностью
        virtual bool tick(Unit&, uint32_t tickNumber){ return false; }

    protected:
        std::shared_ptr<GameField> gameField;
        std::shared_ptr<UnitHeap>  unitHeap;
        sw::EventLog eventLog;
        AI() = delete;
        AI(std::shared_ptr<GameField>& gf, std::shared_ptr<UnitHeap>& uh)
            : gameField(gf), unitHeap(uh)
        {
        }
    };
}

