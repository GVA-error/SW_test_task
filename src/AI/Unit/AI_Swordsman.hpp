#pragma once

#include "AI/Unit/AI_Unit.hpp"

namespace sw::AI
{
    // Описывает поведение мечника во время хода
    class AI_Swordsman : public AI_Unit
    {
    public:
        AI_Swordsman(std::shared_ptr<sw::entities::GameField>&, std::shared_ptr<UnitHeap>&);
        virtual ~AI_Swordsman() {};

        bool tick(sw::entities::Unit&, uint32_t tickNumber) override;
    };
}

