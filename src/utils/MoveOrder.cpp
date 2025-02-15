#include "MoveOrder.h"

#include "entities/UnitEnums.h"

namespace sw::utils
{
    MoveOrder::MoveOrder() {}

    void MoveOrder::clearDead()
    {
        if (f_clearDead)
            while (order.size())
            {
                auto nextId = order.front();
                if (deadSet.find(nextId) != deadSet.end())
                {
                    deadSet.erase(nextId);
                    order.pop();
                    continue;
                }
                break;
            }
    }

    void MoveOrder::next()
    {
        clearDead();
        if (order.size() == 0)
            return;
        auto nextId = order.front();
        order.pop();
        order.push(nextId);
    }

    uint32_t MoveOrder::get()
    {
        clearDead();
        if (order.size() == 0)
            return entities::UNDEFINED_UNIT_ID;
        auto cur = order.front();
        assert(cur != entities::UNDEFINED_UNIT_ID);
        if (f_clearDead) // Если мёртвые чистятся
            assert(deadSet.find(cur) == deadSet.end());
        return cur;
    }

    void MoveOrder::push(uint32_t unitId)
    {
        order.push(unitId);
    }

    void MoveOrder::erase(uint32_t unitId)
    {
        deadSet.insert(unitId);
    }

    void MoveOrder::erase(const std::unordered_set<uint32_t>& unitIds)
    {
        deadSet.insert(unitIds.begin(), unitIds.end());
    }

    uint32_t MoveOrder::size() const
    {
        return order.size();
    }

}
