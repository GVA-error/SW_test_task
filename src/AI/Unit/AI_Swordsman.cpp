#include "AI_Swordsman.hpp"

#include "Entities/UnitEnums.hpp"
#include "AI/Unit/Primitives/pAI_MeleeAttack.hpp"
#include "AI/Unit/Primitives/pAI_March.hpp"

namespace sw::AI
{
    using namespace sw::entities;

    AI_Swordsman::AI_Swordsman(std::shared_ptr<sw::entities::GameField>& gf, std::shared_ptr<UnitHeap>& uh)
        : AI_Unit(gf, uh)
    {
    }

    bool AI_Swordsman::tick(sw::entities::Unit& u, uint32_t tickNumber)
    {
        // Пробуем атаковать
        bool f_activity = primitive::pAI_tryToMeleeAttack(gameField, unitHeap, u, tickNumber,
                                                          eventLog, UnitAttributes::Strength);
        if (f_activity)
            return true;

        // Атаковать было не кого, делаем шаг или ждём исчезновения динамического препятствия.
        f_activity = primitive::pAI_tryToStep(gameField, u, tickNumber, eventLog);
        if (f_activity)
            return true;

        // Доступных действий нет.
        return false;
    }

}
