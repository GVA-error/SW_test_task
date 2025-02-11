#ifndef UNITENUMS_H
#define UNITENUMS_H

// Различные перечисления используемые в стат блоке юнитов

namespace sw::entities
{

    // Механики позволенные для юнита
    enum UnitMechanic {
        MOVE,
        RANGE_ATTACK,
        MELEE_ATTACK
    };

    // Характеристики юнита.
    enum UnitAttributes {
        Strength,
        Agility,
        Range
    };

    // Переменные статусы и эффекты.
    enum UnitState
    {
        HP,
        FRACTION, // Фракция юнита. Кого он считает другом, кого врагом.
    };

    // Различные опции генерации юнита. Используется spawn* механиками
    enum UnitType
    {
        LAND_SOLID, // Юнит занимает наземную клетку на поле
    };
}

#endif // UNITENUMS_H
