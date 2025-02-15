#ifndef UNITSHEAP_H
#define UNITSHEAP_H

#include <cstdint>
#include <unordered_map>
#include <unordered_set>

#include "Unit.h"

namespace sw::entities
{
    using namespace sw::entities;
    // Хранит юнитов
    class UnitHeap
    {
    public:
        void  add(Unit&&);
        void  add(uint32_t unitId, const std::string& name);
        Unit& unitById(uint32_t unitId);
        bool  contains(uint32_t unitId) const;
        void  erase(uint32_t unitId);
        void  erase(const std::unordered_set<uint32_t>& unitId);

        // Проверка корректно ли были удалены все мёртвые юниты.
        bool  isContainsDead() const;

        UnitHeap();
        virtual ~UnitHeap(){}
    protected:
        std::unordered_map<uint32_t, Unit> heap;
    };
}

#endif // UNITSHEAP_H
