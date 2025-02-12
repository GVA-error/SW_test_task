#include "AI_Hunter.h"
#include "entities/UnitEnums.h"
#include "AI/primitives/pai_rangeattack.h"
#include "AI/primitives/pai_meleeattack.h"
#include "AI/primitives/pai_march.h"

namespace sw::AI
{
    using namespace sw::entities;

    AI_Hunter::AI_Hunter(std::shared_ptr<sw::entities::GameField>& gf)
        : AI(gf)
    {
    }

    bool AI_Hunter::tick(sw::entities::Unit& u, uint32_t tickNumber)
    {
        // Сначала пробуем атаковать издали
        bool f_activity = primitive::pAI_tryToRangeAttack(gf, u, tickNumber, eventLog, UnitAttributes::Agility);
        if (f_activity)
            return true;

        // Издали атаковать не вышло, пробуем вблизи
        f_activity = primitive::pAI_tryToMeleeAttack(gf, u, tickNumber, eventLog, UnitAttributes::Strength);
        if (f_activity)
            return true;

        // Атаковать было не кого, делаем шаг.
        f_activity = primitive::pAI_tryToStep(gf, u, tickNumber, eventLog);
        if (f_activity)
            return true;

        return false;
    }
}
