#pragma once

#include <assert.h>
#include <cstdint>
#include <queue>
#include <vector>
#include <unordered_set>

namespace sw::utils
{
    // Зацикленная ленивая очередь ходов.
    class MoveOrder
    {
        // Чистить ли очередь от мертвецов
        const bool f_clearDead = true;
        // Размер заранее выделенной памяти.
        // Важно для лучшей аммортизированности getBuffer.
        // так как getBuffer.push_back() на низких capacity не так эффективен
        const uint32_t preReserveSize = 10;
    public:
        MoveOrder();
        virtual ~MoveOrder() {};

        // Добавление/удаление юнита из очереди
        void push(uint32_t unitId);
        void erase(const std::unordered_set<uint32_t>& unitIds);
        void erase(uint32_t unitId);
        uint32_t size() const;
        // Вернёт готовую для использования очерёдность хода.
        const std::vector<uint32_t> getTurnQueue();
    private:
        // mutable требуется для ленивого clearDead
        // очерёдность ходов
        mutable std::queue<uint32_t> order;
        // Будут удалены при следующем обращении.
        mutable std::unordered_set<uint32_t> deadSet;
        // Буфер для лучшей амортизации при формировании
        std::vector<uint32_t> getBuffer;
        // Для итерирования по кругу
        void next();
        // Удаляем встреченных мертвецов
        // Требуется константность так как делаем это лениво из get()
        void clearDead() const;
        uint32_t get() const;
    };

}

