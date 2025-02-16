#include "Coordinates.hpp"

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

    uint32_t distance(const FieldPos& a, uint32_t x, uint32_t y)
    {
        FieldPos b;
        b.x = x;
        b.y = y;
        return distance(a, b);
    }

    std::list<XY_vert> getAllowedMovePosition(const XY_vert& p)
    {
        std::list<XY_vert> res;
        XY_vert neighbor;
        if (p.x > 0)
        {
            //
            // n p
            //
            neighbor = p;
            neighbor.x--;
            res.push_back(neighbor);
            //
            //   p
            // n
            neighbor.y++;
            res.push_back(neighbor);
        }
        if (p.y > 0)
        {
            //   n
            //   p
            //
            neighbor = p;
            neighbor.y--;
            res.push_back(neighbor);
            //     n
            //   p
            //
            neighbor.x++;
            res.push_back(neighbor);
        }
        if (p.x > 0 && p.y > 0)
        {
            // n
            //   p
            //
            neighbor = p;
            neighbor.x--;
            neighbor.y--;
            res.push_back(neighbor);
        }
        //
        //   p n
        //
        neighbor = p;
        neighbor.x++;
        res.push_back(neighbor);
        //
        //   p
        //     y
        neighbor.y++;
        res.push_back(neighbor);
        //
        //   p
        //   n
        neighbor = p;
        neighbor.y++;
        res.push_back(neighbor);
        return res;
    }

    std::list<XY_manh>  getAllowedMovePosition(const XY_manh& p)
    {
        std::list<XY_manh> res;
        XY_manh neighbor;
        if (p.x > 0)
        {
            //
            // n p
            //
            neighbor = p;
            neighbor.x--;
            res.push_back(neighbor);
        }
        if (p.y > 0)
        {
            //   n
            //   p
            //
            neighbor = p;
            neighbor.y--;
            res.push_back(neighbor);
        }
        //
        //   p n
        //
        neighbor = p;
        neighbor.x++;
        res.push_back(neighbor);
        //
        //   p
        //   n
        neighbor = p;
        neighbor.y++;
        res.push_back(neighbor);
        return res;
    }

    std::list<XYZ_vert> getAllowedMovePosition(const XYZ_vert& p)
    {
        XY_vert d2p;
        d2p.x = p.x;
        d2p.y = p.y;
        auto resD2 = getAllowedMovePosition(d2p);
        std::list<XYZ_vert> resD3;
        for (const auto& rd2 : resD2)
        {
            XYZ_vert rd3;
            rd3.x = rd2.x;
            rd3.y = rd2.y;
            rd3.x = p.z;
            resD3.push_back(rd3);
        }
        return resD3;
    }
}
