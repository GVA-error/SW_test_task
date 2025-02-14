#include "unitsheap.h"

namespace sw::entities
{
    void UnitHeap::addUnit(Unit& u)
    {
        heap[u.getId()] = u;
    }

    Unit& UnitHeap::unitById(uint32_t unitId)
    {
        return heap[unitId];
    }

    bool UnitHeap::contains(uint32_t unitId) const
    {
        return heap.find(unitId) != heap.end();
    }

    UnitHeap::UnitHeap()
    {

    }


}
