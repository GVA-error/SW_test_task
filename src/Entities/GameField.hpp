#pragma once

#include <assert.h>
#include <cstdint>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>

#include <IO/Commands/March.hpp>
#include <IO/Commands/SpawnHunter.hpp>
#include <IO/Commands/SpawnSwordsman.hpp>

#include "Entities/Unit.hpp"
#include "Utils/Coordinates.hpp"
#include "Utils/UnitPaths.hpp"

namespace sw::entities
{
    using namespace sw::utils;
    /*
     *  Хранит и обрабатывает пространственную информацию.
     *  Является бекэндом для позиций юнитов и препятствий.
     *  Отвечает за коллизии, поиск целей и т. п.
     *  FieldPos - система координат из utils/Coordinates.h
    */
    class GameField
    {
    public:
        GameField() = delete;
        virtual ~GameField(){};
        GameField(uint32_t width, uint32_t height);

        // Добавляет физический бекенд для юнита
        bool addUnit(sw::entities::Unit&, uint32_t x, uint32_t y);

        // Обновляет позицию юнита. При коллизии юнит ищет обход через клетку ближайшую от цели марша.
        // Для более простого решения коллизий быстрых юнитов, всегда двигаемся на один шаг.
        // Пример: если юнит обладает скоростью 5, то step() должна быть вызвана 5 раз за ход.
        // Если юнит двигался или ждал, возвращает true.
        bool step(Unit&);

        // Обозначаем юнита как мёртвого. Теперь он некуда не пойдёт.
        // Но будет препятствием пока не будет вызвана eraseDeadUnits
        void kill(uint32_t unitId);
        bool isDead(uint32_t unitId) const;
        bool isDead(const Unit&) const;

        // Обновляет Позицию в которую стремиться юнит.
        // исходит от command::March
        void March(uint32_t unitId, uint32_t targetX, uint32_t targetY);

        // Стремиться ли юнит куда-либо
        bool onMarch(const Unit&) const;
        // .. куда
        const FieldPos& getMarchTargetPos(const Unit&) const;

        // Возвращает id всех юнитов в Coordinates::distance(radius) и центром в точке поля
        // f_liveOnly - ищем только живых
        // minRadius  - минимальное расстояние для поиска
        // maxRadius  - .. максимальное
        std::list<uint32_t> getUnitsInRadius(const FieldPos&, uint32_t minRadius, uint32_t maxRadius, bool f_liveOnly=true) const;
        // .. с центром в позиции юнита
        std::list<uint32_t> getUnitsInRadius(const Unit& u, uint32_t minRadius, uint32_t maxRadius, bool f_liveOnly=true) const;
        std::list<uint32_t> getUnitsInRadius(uint32_t unitId, uint32_t minRadius, uint32_t maxRadius, bool f_liveOnly=true) const;
        // .. вернёт случайного юнита в радиусе
        uint32_t getRandomUnitInRadius(const Unit& u, uint32_t minRadius, uint32_t maxRadius, bool f_liveOnly=true) const;

        // Сколько юнитов мертвы.
        uint32_t deadSetSize() const;
        std::unordered_set<uint32_t> getDeadSet() const;

        // Чистим поле от трупов
        void eraseDeadUnits();

        // Геттеры размеров поля
        uint32_t getWidth()  const;
        uint32_t getHeight() const;

        // Позиция юнита на поле
        const FieldPos& getUnitPosition(const sw::entities::Unit&) const;
        const FieldPos& getUnitPosition(uint32_t unitId) const;
        // Позиция вне полу
        bool isOutOfField(const FieldPos&) const;
        bool isOutOfField(uint32_t x, uint32_t y) const;

    private:
        // Размеры поля
        uint32_t width  = 0;
        uint32_t height = 0;

        // Список id умерших юнитов
        // Требуется для механики начала хода - очистки поля от тел.
        std::unordered_set<uint32_t> deadSet;

        // Список всех юнитов на данной позиции
        std::map<FieldPos, std::unordered_set<uint32_t>> unitsOnPosition;

        // Текущая позиция юнита на поле
        std::unordered_map<uint32_t, FieldPos> unitPosition;

        // Является ли юнит наземным препятствием
        std::unordered_map<uint32_t, bool> unitIsLandObstacle;

        // Есть ли на клетке юнит, мешающий пройти по земле
        std::set<FieldPos> landObstacle;

        // Просчитывает пути, давая следующую точку для шага
        sw::utils::UnitPaths unitPaths;

        // Полное уничтожение информации о юните c поля
        void deleteUnit(uint32_t unitId);
        // Если на позиции есть живые юниты, то вернёт id случайного, иначе UNDEFINED_UNIT_ID
        uint32_t findRandomLiveUnitInPos(uint32_t x, uint32_t y) const;
        // Даёт все позиции в квадрате со стороной 2*radius + 1 и центром в позиции поля.
        std::list<FieldPos> getPositionsInSqrtRadius(const FieldPos&, uint32_t radius) const;
    };
}

