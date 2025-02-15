#ifndef UNITSHEAP_H
#define UNITSHEAP_H

#include <cstdint>
#include <unordered_map>

#include "Unit.h"

namespace sw::entities
{
    using namespace sw::entities;
    // Хранит юнитов
    class UnitHeap
    {
    public:
        void  addUnit(Unit&&);
        void  addUnit(uint32_t unitId, const std::string& name);
        Unit& unitById(uint32_t unitId);
        bool  contains(uint32_t unitId) const;
        void  eraseUnit(uint32_t unitId);

        UnitHeap();
        virtual ~UnitHeap(){}
    protected:
        std::unordered_map<uint32_t, Unit> heap;
    };
}

#endif // UNITSHEAP_H
