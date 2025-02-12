#ifndef AI_H
#define AI_H

#include <memory>
#include "entities/gamefield.h"
#include "entities/Unit.h"
#include "IO/System/EventLog.hpp"

namespace sw::AI
{
    class AI
    {
    public:
        virtual ~AI() {};

        // Описываем, что юнит делает во время хода
        // Возвращает был ли юнит активен во время хода
        // Ожидание считаем активностью
        virtual bool tick(sw::entities::Unit&, uint32_t tickNumber) = 0;

    protected:
        std::shared_ptr<sw::entities::GameField> gf;
        sw::EventLog eventLog;
        AI() = delete;
        AI(std::shared_ptr<sw::entities::GameField>& gf)
            : gf(gf)
        {
        }
    };
}

#endif // AI_H
