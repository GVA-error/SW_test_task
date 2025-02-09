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

        GameField();

        // Добавляет бекенд для юнита
        void addUnit(const sw::entities::Unit&);

        // Обновляет позицию юнита. При коллизии юнит не меняет позию.
        // Для более простого решения коллизий быстрых юнитов, всегда двигаемся на один шаг.
        // Пример: если юнит обладает скоростью 5, то должна быть вызвана 5 раз за ход.
        // При простое возвращает false.
        bool step(sw::entities::Unit&) const;

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

    private:
        // Список id умерших юнитов
        // Требуется для механики начала хода - очистки поля от тел.
        std::set<uint32_t> deadSet;

        // Список всех юнитов на данной позиции
        std::map<sw::utils::FieldPos, std::set<uint32_t>> unitsOnPosition;

        // Есть ли на клетке юнит, мешающий пройти по земле
        std::map<sw::utils::FieldPos, bool> landObstacle;

        // Просчитывает пути, давая следующую точку для шага
        sw::utils::UnitPaths unitPaths;
    };
}

#endif // GAMEFIELD_H
