#include "UnitsHeap.hpp"

namespace sw::entities
{
    UnitHeap::UnitHeap()
    {

    }

    void UnitHeap::add(Unit&& u)
    {
        heap[u.getId()] = std::move(u);
    }

    void UnitHeap::add(uint32_t unitId, const std::string& name)
    {
        add(Unit(unitId, name));
    }

    Unit& UnitHeap::unitById(uint32_t unitId)
    {
        return heap[unitId];
    }

    bool UnitHeap::contains(uint32_t unitId) const
    {
        return heap.find(unitId) != heap.end();
    }

    void UnitHeap::erase(uint32_t unitId)
    {
        heap.erase(unitId);
    }

    void UnitHeap::erase(const std::unordered_set<uint32_t>& unitIds)
    {
        for (auto unitId : unitIds)
            erase(unitId);
    }

    bool UnitHeap::isContainsDead() const
    {
        for (auto& [unitId, unit] : heap)
            if (unit.isDead())
                return true;
        return false;
    }


}
