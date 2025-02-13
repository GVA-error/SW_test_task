#ifndef UNITENUMS_H
#define UNITENUMS_H

#include <cstdint>

// Различные перечисления используемые в стат блоке юнитов

namespace sw::entities
{

    // Механики позволенные для юнита
    // Необходим для более удобной подмены AI и временных запретов механик
    // К примеру, если у лучника кончились стрелы, запретив механику дальней атаки он не будет искать цель
    // Или если мы хотим только проверить механику башни, то можем использовать AI лучника, только с возможностью стрелять.
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
    enum UnitStatus
    {
        HP,
        FRACTION, // Фракция юнита. Кого он считает другом, кого врагом.
    };

    // Различные опции генерации юнита. Используется spawn* механиками
    enum UnitType
    {
        LAND_SOLID, // Юнит занимает наземную клетку на поле
    };

    // Не определённый id юнита
    static const uint32_t UNDEFINED_UNIT_ID = UINT32_MAX;
}

#endif // UNITENUMS_H
