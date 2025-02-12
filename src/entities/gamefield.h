#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <assert.h>
#include <cstdint>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <IO/Commands/March.hpp>
#include <IO/Commands/SpawnHunter.hpp>
#include <IO/Commands/SpawnSwordsman.hpp>

#include "utils/Coordinates.h"
#include "utils/UnitPaths.h"
#include "entities/Unit.h"

namespace sw::entities
{
    using namespace sw::utils;
    /*
     *  Хранит и обрабатывает пространственую информацию.
     *  Является бекэндом для позиций юнитов и препятствий.
     *  Отвечает за коллизии, поиск целей и т. п.
     *  FieldPos - система координат из utils/Coordinates.h
    */
    class GameField
    {
    public:
        GameField() = delete;
        GameField(uint32_t w, uint32_t h);

        // Добавляет бекенд для юнита
        bool addUnit(sw::entities::Unit&, uint32_t x, uint32_t y);

        // Обновляет позицию юнита. При коллизии юнит не меняет позию, а ждёт.
        // Для более простого решения коллизий быстрых юнитов, всегда двигаемся на один шаг.
        // Пример: если юнит обладает скоростью 5, то step() должна быть вызвана 5 раз за ход.
        // Если юнит двигался или ждал, возвращает true.
        bool step(sw::entities::Unit&);

        // Обозначаем юнита как мёртвого. Теперь он не куда не пойдёт.
        // Но будет препядствием пока не будет вызвана eraseDeadUnits
        void kill(uint32_t unitId);

        // Обновляет Позицию в которую стремится юнит.
        // исходит от command::March
        void March(uint32_t unitId, uint32_t targetX, uint32_t targetY);

        // Двигается ли юнит куда либо
        bool onMarch(const sw::entities::Unit&) const;

        // Возвращает id всех юнитов в квадрате со стороной 2*radius+1 и центром в точке поля
        std::list<uint32_t> getUnitsInRadius(const FieldPos&, uint32_t radius) const;

        // Сколько юнитов мертвы.
        uint32_t deadSetSize() const;

        // Чистим поле от трупов
        void eraseDeadUnits();

        // Геттеры размеров поля
        uint32_t getWidth()  const;
        uint32_t getHeight() const;

        FieldPos getUnitPosition(uint32_t unitId) const;

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
        std::map<FieldPos, bool> landObstacle;

        // Просчитывает пути, давая следующую точку для шага
        sw::utils::UnitPaths unitPaths;

        void deleteUnit(uint32_t unitId);
    };
}

#endif // GAMEFIELD_H
