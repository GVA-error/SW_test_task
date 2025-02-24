#pragma once

#include <cstdint>
#include <map>
#include <set>

#include "Utils/Coordinates.hpp"

namespace sw::utils
{
    // Класс для работы с путями передвижения юнитов.
    class UnitPaths
    {
    public:
        UnitPaths();
        virtual ~UnitPaths(){};

        // Устанавливает точку цели для юнита
        void setUnitTarget(uint32_t id, const FieldPos&);
        void setUnitTarget(uint32_t id, uint32_t x, uint32_t y);
        void eraseUnitPaths(uint32_t id);

        // Передвигает юнита на новую позицию из возможных, на один шаг. Выбирает наиболее близкую к цели.
        // Дойдя до финальной точки, юнит остановится.
        // unitPos - позиция, которую меняем.
        bool step(uint32_t id, const std::set<FieldPos>& landObstacle,
                  FieldPos& unitPos, uint32_t fieldWidth, uint32_t fieldHeight);
        // Если юниту не важны препятствия
        bool step(uint32_t id, FieldPos& unitPos, uint32_t fieldWidth, uint32_t fieldHeight);

        bool haveTarget(uint32_t id) const;
        const FieldPos& getUnitTarget(uint32_t id) const;

    private:
        // По id возвращает позицию цели юнита
        std::map<uint32_t, FieldPos> target;

    };
}

