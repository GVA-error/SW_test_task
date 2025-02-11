#ifndef AI_SPAWNHUNTER_H
#define AI_SPAWNHUNTER_H

#include "ai.h"


namespace sw::AI
{

    class AI_SpawnHunter : public AI
    {
    public:
        AI_SpawnHunter(std::shared_ptr<sw::entities::GameField>&);
        virtual ~AI_SpawnHunter() {};

        bool tick(sw::entities::Unit&) override;
    };

}

#endif // AI_SPAWNHUNTER_H
