#ifndef GAMEFIELD_H
#define GAMEFIELD_H


#include <cstdint>
#include <set>
#include <map>
#include <list>
#include <IO/Commands/March.hpp>
#include <IO/Commands/SpawnHunter.hpp>
#include <IO/Commands/SpawnSwordsman.hpp>

#include "utils/Coordinates.h"
#include "utils/UnitPaths.h"
#include "entities/Unit.h"

namespace sw::entities
{
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

        // Обновляет позицию юнита. При коллизии юнит не меняет позию.
        // Для более простого решения коллизий быстрых юнитов, всегда двигаемся на один шаг.
        // Пример: если юнит обладает скоростью 5, то step() должна быть вызвана 5 раз за ход.
        // Если юнит двигался или ждал, возвращает true.
        bool step(sw::entities::Unit&);

        // Обозначаем юнита как мёртвого. Теперь он не куда не пойдёт.
        // Но будет препядствием пока не будет вызвана eraseDeadUnits
        void kill(uint32_t unitId);

        // Обновляет Позицию в которую стремится юнит.
        void March(uint32_t unitId, uint32_t targetX, uint32_t targetY);

        // Двигается ли юнит куда либо
        bool onMarch(const sw::entities::Unit&) const;

        // Возвращает id всех юнитов
        std::list<uint32_t> getUnitsInDistance() const;

        // Сколько юнитов мертвы.
        uint32_t deadSetSize() const;

        // Чистим поле от трупов
        void eraseDeadUnits();

        // Геттеры размеров поля
        uint32_t getWidth()  const;
        uint32_t getHeight() const;

        sw::utils::FieldPos getUnitPosition(uint32_t unitId) const;

    private:
        // Размеры поля
        uint32_t width  = 0;
        uint32_t height = 0;

        // Список id умерших юнитов
        // Требуется для механики начала хода - очистки поля от тел.
        std::set<uint32_t> deadSet;

        // Список всех юнитов на данной позиции
        std::unordered_map<sw::utils::FieldPos, std::set<uint32_t>> unitsOnPosition;

        // Текущая позиция юнита на поле
        std::map<uint32_t, sw::utils::FieldPos> unitPosition;

        // Является ли юнит наземным препятствием
        std::map<uint32_t, bool> unitIsLandObstacle;

        // Есть ли на клетке юнит, мешающий пройти по земле
        std::unordered_map<sw::utils::FieldPos, bool> landObstacle;

        // Просчитывает пути, давая следующую точку для шага
        sw::utils::UnitPaths unitPaths;
    };
}

#endif // GAMEFIELD_H
