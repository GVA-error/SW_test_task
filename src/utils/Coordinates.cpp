#include "Coordinates.h"

namespace sw::utils
{
    uint32_t distance(const XY_manh& a, const XY_manh& b)
    {
        return abs(int32_t(a.x) - int32_t(b.x)) + abs(int32_t(a.y) - int32_t(b.y));
    }

    uint32_t distance(const XY_vert& a, const XY_vert& b)
    {
        return std::max(abs(int32_t(a.x) - int32_t(b.x)), abs(int32_t(a.y) - int32_t(b.y)));
    }

    uint32_t distance(const XYZ_vert& a, const XYZ_vert& b)
    {
        return std::max(abs(int32_t(a.x) - int32_t(b.x)), abs(int32_t(a.y) - int32_t(b.y))
                                                              + abs(int32_t(a.z) - int32_t(b.z)));
    }
}
