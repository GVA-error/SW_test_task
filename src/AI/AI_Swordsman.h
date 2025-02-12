#ifndef AI_SWORDSMAN_H
#define AI_SWORDSMAN_H

#include "ai.h"

namespace sw::AI
{
    // Описывает поведение мечника во время хода
    class AI_Swordsman : public AI
    {
    public:
        AI_Swordsman(std::shared_ptr<sw::entities::GameField>&);
        virtual ~AI_Swordsman() {};

        bool tick(sw::entities::Unit&, uint32_t tickNumber) override;
    };
}

#endif // AI_SWORDSMAN_H
