#pragma once

#include <assert.h>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>

#include "Unit.hpp"

namespace sw::entities
{
    using namespace sw::entities;
    // Хранит юнитов
    class UnitHeap
    {
    public:
        UnitHeap();
        virtual ~UnitHeap(){}

        void  add(Unit&&);
        void  add(uint32_t unitId, const std::string& name);
        Unit& unitById(uint32_t unitId);
        bool  contains(uint32_t unitId) const;
        void  erase(uint32_t unitId);
        void  erase(const std::unordered_set<uint32_t>& unitId);

        // Проверка корректно ли были удалены все мёртвые юниты.
        bool  isContainsDead() const;

    protected:
        std::unordered_map<uint32_t, Unit> heap;
    };
}

