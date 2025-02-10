#ifndef COORDINATES_H
#define COORDINATES_H

#include <cstdint>
#include <cmath>
#include <functional>

namespace sw::utils
{
    // Определяем систему координат в зависимости от выбранного типа точек

    // Возможность ходить по диагонали
    struct XY_vert
    {
        uint32_t x;
        uint32_t y;

        // Для мапов и сетов.
        bool operator==(const XY_vert& other) const {
            return x == other.x && y == other.y;
        }
    };

    // Возможность ходить только по одной оси одновременно
    // Предпологается манхэттенская норма
    struct XY_manh
    {
        uint32_t x;
        uint32_t y;

        // Для мапов и сетов.
        bool operator==(const XY_manh& other) const {
            return x == other.x && y == other.y;
        }
    };

    // Возможность ходить по диагонали
    // Требуется для механики летающих юнитов
    struct XYZ_vert
    {
        uint32_t x;
        uint32_t y;
        uint32_t z = 0;

        // Для мапов и сетов.
        bool operator==(const XYZ_vert& other) const {
            return x == other.x && y == other.y && z == other.z;
        }
    };

    // манхетанская норма
    uint32_t distance(const XY_manh& a, const XY_manh& b)
    {
        return abs(int32_t(a.x) - int32_t(b.x)) + abs(int32_t(a.y) - int32_t(b.y));
    }

    // если разрешено двигатся по диагонали
    uint32_t distance(const XY_vert& a, const XY_vert& b)
    {
        return std::max(abs(int32_t(a.x) - int32_t(b.x)), abs(int32_t(a.y) - int32_t(b.y)));
    }

    // если разрешено двигатся по диагонали
    uint32_t distance(const XYZ_vert& a, const XYZ_vert& b)
    {
        return std::max(abs(int32_t(a.x) - int32_t(b.x)), abs(int32_t(a.y) - int32_t(b.y))
               + abs(int32_t(a.z) - int32_t(b.z)));
    }

    typedef XY_vert FieldPos;
}

// Хеш функции для мапов и сетов
namespace std {
    template <>
    struct hash<sw::utils::FieldPos> {
        size_t operator()(const sw::utils::FieldPos& p) const {
            size_t h1 = hash<int>{}(p.x);
            size_t h2 = hash<int>{}(p.y);
            // Комбинируем хеши
            return h1 ^ (h2 << 1);
        }
    };
}


#endif // COORDINATES_H
