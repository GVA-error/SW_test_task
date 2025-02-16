#pragma once

#include <cstdint>
#include <unordered_map>
#include <string>

#include "UnitEnums.hpp"

namespace sw::entities
{
    // Описывает юнита.
    // То какие механики он может применять, его характеристики, временные состояния и т. д.
    // Для создания используeм sw::mechanics::Spawn()
    class Unit
    {
    public:
        Unit(){};
        virtual ~Unit(){};

        // id - уникальный идинтификатор юнита
        // name - по умолчанию обозначает тип юнита.
        Unit(uint32_t id, const std::string& name = "defaultUnit");
        // Копирование юнита опасно, так как может нарушить поведение AI
        Unit(const Unit&) = delete;

        const uint32_t    getId() const;
        const std::string getName() const;

        // Геттеры статблока
        bool isAllowed(const UnitMechanic&) const;
        int32_t getAttribute(const UnitAttributes&) const;
        int32_t getState(const UnitStatus&) const;
        int32_t is(const UnitType&) const;

        // Обновляет значения стат блока
        void set(const UnitMechanic&, bool f = true);
        void set(const UnitAttributes&, int32_t value);
        void set(const UnitStatus&, int32_t value);
        void set(const UnitType&);

        // Контекстные геттеры
        bool isDead() const;
        int32_t getCurrentHP() const;

        // Контекстные сеттеры
        void takeDamage(int32_t damageHpImpact);

    private:
        // typeName используется для более простого дебага
        std::string name;
        uint32_t id;

        // Был ли юнит создан корректно, не было ли иных ошибок.
        bool f_isCorrect = true;
        // Описание причины не корректности
        std::string incorrectnessReason;

        // Стат блок
        std::unordered_map<UnitMechanic,   bool>    mechanic;
        std::unordered_map<UnitAttributes, int32_t> attributes;
        std::unordered_map<UnitStatus,     int32_t> status;
        std::unordered_map<UnitType,       bool>    type;

    };

};
