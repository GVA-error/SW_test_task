#ifndef UNITPATHS_H
#define UNITPATHS_H

#include <cstdint>
#include <map>
#include <set>

#include "utils/Coordinates.h"

namespace sw::utils
{
    // Класс для работы с путями передвижения юнитов.
    class UnitPaths
    {
    public:
        UnitPaths();

        // Устанавливает точку цели для юнита
        void setUnitTarget(uint32_t id, const FieldPos&);
        void setUnitTarget(uint32_t id, uint32_t x, uint32_t y);

        // Передвигает юнита на новую позицию из возможных, на один шаг. Выбирает наиболее близкую к цели.
        // Дойдя до финальной точки, юнит остановится.
        // unitPos - позиция которую меняем.
        bool step(uint32_t id, const std::set<FieldPos>& landObstacle,
                  FieldPos& unitPos);
        // Если юниту не важны препятствия
        bool step(uint32_t id, FieldPos& unitPos);

        bool haveTarget(uint32_t id) const;

    private:
        // По id возвращает позицию цели юнита
        std::map<uint32_t, FieldPos> target;

    };
}

#endif // UNITPATHS_H
