#pragma once

#include "AI_Unit.hpp"

namespace sw::AI
{
    // Описывает поведение охотника во время хода
    class AI_Hunter : public AI_Unit
    {
    public:
        AI_Hunter(std::shared_ptr<sw::entities::GameField>&, std::shared_ptr<UnitHeap>&);
        virtual ~AI_Hunter() {};

        bool tick(sw::entities::Unit&, uint32_t tickNumber) override;
    };
}

