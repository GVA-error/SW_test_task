#ifndef AI_SPAWNSWORDSMAN_H
#define AI_SPAWNSWORDSMAN_H

#include "ai.h"

namespace sw::AI
{
    class AI_SpawnSwordsman : public AI
    {
    public:
        AI_SpawnSwordsman(std::shared_ptr<sw::entities::GameField>&);
        virtual ~AI_SpawnSwordsman() {};

        bool tick(sw::entities::Unit&) override;
    };
}

#endif // AI_SPAWNSWORDSMAN_H
