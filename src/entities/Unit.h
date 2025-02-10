#ifndef UNIT_H
#define UNIT_H

#include <cstdint>
#include <map>
#include <string>

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

    // Переменные статусы, эффекты и таймеры.
    enum UnitState
    {
        HP
    };

    // Описывает поведение юнита.
    // То какие механики он может применять, его характеристики, временные состояния и т. д.
    // Для создания использум sw::mechanics::spawn::*
    class Unit
    {
    public:

        Unit() = delete;

        // id - уникальный идинтификатор юнита
        // typeName - служит в целях дебага
        Unit(uint32_t id, const std::string& typeName = "defaultUnit");

        const std::string getTypeName() const;
        const uint32_t    getId() const;

        bool isAllowed(const UnitMechanic&) const;
        int32_t getAttribute(const UnitAttributes&) const;
        int32_t getState(const UnitState&) const;

        // Обновляет численные значения
        void set(const UnitMechanic&, bool f = true);
        void set(const UnitAttributes&, int32_t);
        void set(const UnitState&, int32_t);

        // дебаг информация о юните
        bool isCorrect() const;
        void markAsIncorrect();

    private:
        std::string typeName;
        uint32_t id;

        // Был ли юнит создан корректно
        bool f_isCorrect = true;

        // Стат блок
        std::map<UnitMechanic,   bool>    mechanic;
        std::map<UnitAttributes, int32_t> attributes;
        std::map<UnitState,      int32_t> status;
    };

};

#endif // UNIT_H
