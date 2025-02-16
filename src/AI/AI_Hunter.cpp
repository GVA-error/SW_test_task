#include "Entities/UnitEnums.hpp"
#include "AI/Primitives/pAI_RangeAttack.hpp"
#include "AI/Primitives/pAI_MeleeAttack.hpp"
#include "AI/Primitives/pAI_March.hpp"
#include "AI_Hunter.hpp"

namespace sw::AI
{
    using namespace sw::entities;

    AI_Hunter::AI_Hunter(std::shared_ptr<sw::entities::GameField>& gf, std::shared_ptr<UnitHeap>& uh)
        : AI(gf, uh)
    {
    }

    bool AI_Hunter::tick(sw::entities::Unit& u, uint32_t tickNumber)
    {
        // Сначала пробуем атаковать издали
        bool f_activity = primitive::pAI_tryToRangeAttack(gameField, unitHeap, u, tickNumber,
                                                          eventLog, UnitAttributes::Agility);
        if (f_activity)
            return true;

        // Издали атаковать не вышло, пробуем вблизи
        f_activity = primitive::pAI_tryToMeleeAttack(gameField, unitHeap, u, tickNumber,
                                                     eventLog, UnitAttributes::Strength);
        if (f_activity)
            return true;

        // Атаковать было не кого, делаем шаг.
        f_activity = primitive::pAI_tryToStep(gameField, u, tickNumber, eventLog);
        if (f_activity)
            return true;

        return false;
    }
}
