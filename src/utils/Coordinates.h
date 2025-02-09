#ifndef COORDINATES_H
#define COORDINATES_H

#include <cstdint>
#include <cmath>

namespace sw::utils
{
    // Определяем систему координат в зависимости от выбранного типа точек

    // Возможность ходить только по одной оси одновременно
    // Предпологается манхэттенская норма
    struct XY_manh
    {
        uint32_t x;
        uint32_t y;
    };

    // Возможность ходить по диагонали
    struct XY_vert
    {
        uint32_t x;
        uint32_t y;
    };


    // Возможность ходить только по одной оси одновременно
    // Требуется для механизама летающих юнитов
    // Предпологается манхэттенская норма + z
    struct XYZ_manh
    {
        uint32_t x;
        uint32_t y;
        uint32_t z = 0;
    };

    // Возможность ходить по диагонали
    // Требуется для механизама летающих юнитов
    // Потребуется переопределить расстояние для диагонали
    struct XYZ_eucl
    {
        uint32_t x;
        uint32_t y;
        uint32_t z = 0;
    };

    // манхетанская норма
    uint32_t distance(const XY_manh& a, const XY_manh& b)
    {
        return abs(int32_t(a.x) - int32_t(b.x)) + abs(int32_t(a.y) - int32_t(b.y));
    }

    // для простоты определяем так же
    uint32_t distance(const XY_vert& a, const XY_vert& b)
    {
        return distance(XY_manh(a.x, a.y), XY_manh(a.x, a.y));
    }

    typedef XY_manh FieldPos;
}


#endif // COORDINATES_H
