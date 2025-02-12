#include "AI_Swordsman.h"
#include "entities/UnitEnums.h"
#include "AI/primitives/pai_meleeattack.h"
#include "AI/primitives/pai_march.h"

namespace sw::AI
{
    using namespace sw::entities;

    AI_Swordsman::AI_Swordsman(std::shared_ptr<sw::entities::GameField>& gf)
        : AI(gf)
    {
    }

    bool AI_Swordsman::tick(sw::entities::Unit& u, uint32_t tickNumber)
    {
        // Пробуем атаковать
        bool f_activity = primitive::pAI_tryToMeleeAttack(gf, u, tickNumber, eventLog, UnitAttributes::Strength);
        if (f_activity)
            return true;

        // Атаковать было не кого, делаем шаг или ждём исчезновения динамического препятствия.
        f_activity = primitive::pAI_tryToStep(gf, u, tickNumber, eventLog);
        if (f_activity)
            return true;

        // Доступных действий нет.
        return false;
    }

}
