#ifndef MOVEORDER_H
#define MOVEORDER_H

#include <assert.h>
#include <cstdint>
#include <queue>
#include <vector>
#include <unordered_set>

namespace sw::utils
{
    // Зацикленная очередь ходов.
    class MoveOrder
    {
        // Чистить ли очередь от мертвецов
        const bool f_clearDead = true;
    public:
        // Добавление/удаление юнита из очереди
        void push(uint32_t unitId);
        void erase(const std::unordered_set<uint32_t>& unitIds);
        void erase(uint32_t unitId);
        uint32_t size() const;
        // Вернёт готовую для использования очерёдность хода.
        const std::vector<uint32_t> getTurnQueue();
        MoveOrder();
    private:
        // очерёдность ходов
        std::queue<uint32_t> order;
        // Будут удалены при следующем обращении.
        std::unordered_set<uint32_t> deadSet;
        // Буфер для лучшей амортизации при формировании
        std::vector<uint32_t> getBuffer;
        // Удаляем встреченных мертвецов
        void clearDead();
        // Для итерирования по кругу
        void next();
        uint32_t get();
    };

}

#endif // MOVEORDER_H
