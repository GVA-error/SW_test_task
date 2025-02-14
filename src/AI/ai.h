#ifndef AI_H
#define AI_H

#include <memory>
#include "entities/gamefield.h"
#include "entities/Unit.h"
#include "entities/unitsheap.h"
#include "IO/System/EventLog.hpp"

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
        virtual bool tick(Unit&, uint32_t tickNumber) = 0;

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

#endif // AI_H
