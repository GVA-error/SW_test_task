#include "AI_OrderPreparation.hpp"

namespace sw::AI
{
    using namespace sw::entities;

    void AI_OrderPraparation::orderPreparation(std::shared_ptr<GameField>& gf)
    {
        // Убираем физическое претставление
        auto deadSet = gf->getDeadSet();
        moveOrder->erase(deadSet);
        unitsHeap->erase(deadSet);
        gf->eraseDeadUnits();
        assert(unitsHeap->isContainsDead() == false);
    }

    void AI_OrderPraparation::orderPostHandle(std::shared_ptr<GameField>& gf)
    {

    }

}
