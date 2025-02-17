#include "AI_TurnPreparation.hpp"

namespace sw::AI
{
    using namespace sw::entities;

    void AI_TurnPraparation::turnPreparation(std::shared_ptr<GameField>& gf)
    {
        // Убираем физическое претставление
        auto deadSet = gf->getDeadSet();
        moveOrder->erase(deadSet);
        unitsHeap->erase(deadSet);
        gf->eraseDeadUnits();
        assert(unitsHeap->isContainsDead() == false);
    }

    void AI_TurnPraparation::turnPostHandle(std::shared_ptr<GameField>& gf)
    {

    }

}
