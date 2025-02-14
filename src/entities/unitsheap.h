#ifndef UNITSHEAP_H
#define UNITSHEAP_H

#include <cstdint>
#include <map>

#include "Unit.h"

namespace sw::entities
{
    using namespace sw::entities;
    // Хранит юнитов
    class UnitHeap
    {
    public:
        void  addUnit(Unit&);
        Unit& unitById(uint32_t unitId);
        bool  contains(uint32_t unitId) const;

        UnitHeap();
        virtual ~UnitHeap(){}
    protected:
        std::map<uint32_t, Unit> heap;
    };
}

#endif // UNITSHEAP_H
