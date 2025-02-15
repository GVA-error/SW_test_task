#include "unitsheap.h"

namespace sw::entities
{
    UnitHeap::UnitHeap()
    {

    }

    void UnitHeap::addUnit(Unit&& u)
    {
        heap[u.getId()] = std::move(u);
    }

    void UnitHeap::addUnit(uint32_t unitId, const std::string& name)
    {
        addUnit(Unit(unitId, name));
    }

    Unit& UnitHeap::unitById(uint32_t unitId)
    {
        return heap[unitId];
    }

    bool UnitHeap::contains(uint32_t unitId) const
    {
        return heap.find(unitId) != heap.end();
    }

    void UnitHeap::eraseUnit(uint32_t unitId)
    {
        heap.erase(unitId);
    }

    void UnitHeap::eraseUnit(const std::unordered_set<uint32_t>& unitIds)
    {
        for (auto unitId : unitIds)
            eraseUnit(unitId);
    }

    bool UnitHeap::isContainsDead() const
    {
        for (auto& [unitId, unit] : heap)
            if (unit.isDead())
                return true;
        return false;
    }


}
