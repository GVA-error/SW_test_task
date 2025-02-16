#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>

#include "entities/unitsheap.h"
#include "entities/Unit.h"
#include "entities/gamefield.h"

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

