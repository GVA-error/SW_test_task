#pragma once

#include <cstdint>
#include <cmath>
#include <functional>
#include <list>

namespace sw::utils
{
    // Определяем систему координат в зависимости от выбранного типа точек

    // Базовая структура для возможности использования в *map и *set
    struct MappableCoordinate
    {
        uint32_t x;
        uint32_t y;

        bool operator==(const MappableCoordinate& other) const {
            return x == other.x && y == other.y;
        }
        bool operator<(const MappableCoordinate& other) const {
            if (x == other.x)
                return y < other.y;
            return x < other.x;
        }
    };

    // Возможность ходить по диагонали
    struct XY_vert : MappableCoordinate
    {
    };

    // Возможность ходить только по одной оси одновременно
    // Предпологается манхэттенская норма
    struct XY_manh : MappableCoordinate
    {
    };

    // Возможность ходить по диагонали, но с координатой z
    // Требуется для механики летающих юнитов
    struct XYZ_vert : MappableCoordinate
    {
        uint32_t z = 0;
    };

    typedef XY_vert FieldPos;

    // манхетанская норма
    uint32_t distance(const XY_manh& a, const XY_manh& b);
    // если разрешено двигатся по диагонали
    uint32_t distance(const XY_vert& a, const XY_vert& b);
    // если разрешено двигатся по диагонали
    uint32_t distance(const XYZ_vert& a, const XYZ_vert& b);
    uint32_t distance(const FieldPos& a, uint32_t x, uint32_t y);

    const FieldPos UNDEFINED_POSITION = { UINT32_MAX, UINT32_MAX };

    // Доступные позиции для движения из точки
    // n n n
    // n p n
    // n n n
    std::list<XY_vert>  getAllowedMovePosition(const XY_vert&);
    std::list<XYZ_vert> getAllowedMovePosition(const XYZ_vert&);
    //   n
    // n p n
    //   n
    std::list<XY_manh>  getAllowedMovePosition(const XY_manh&);
}

// Хеш функции для мапов и сетов
namespace std {
    using namespace sw::utils;
    template <>
    struct hash<FieldPos> {
        size_t operator()(const FieldPos& p) const {
            size_t h1 = hash<int>{}(p.x);
            size_t h2 = hash<int>{}(p.y);
            // Комбинируем хеши
            return h1 ^ (h2 << 1);
        }
    };

}

