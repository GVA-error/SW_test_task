#ifndef MOVEORDER_H
#define MOVEORDER_H

#include <assert.h>
#include <cstdint>
#include <queue>
#include <unordered_set>

namespace sw::utils
{

    class MoveOrder
    {
        // Чистить ли очередь от мертвецов
        const bool f_clearDead = true;
    public:
        void next();
        uint32_t get();
        void push(uint32_t unitId);
        void erase(const std::unordered_set<uint32_t>& unitIds);
        void erase(uint32_t unitId);
        uint32_t size() const;
        MoveOrder();
    private:
        // очерёдность ходов
        std::queue<uint32_t> order;
        // Будут удалены при следующем обращении.
        std::unordered_set<uint32_t> deadSet;

        // Удаляем встреченных мертвецов
        void clearDead();
    };

}

#endif // MOVEORDER_H
