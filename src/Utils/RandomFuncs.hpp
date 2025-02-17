#pragma once

#include <cstdint>
#include <cstdlib>
#include <iterator>

namespace sw::utils
{
    // Берём случайный элемент из контейнера
    template <class CONTAINER>
    auto randomChoice(const CONTAINER& cont)
    {
        auto i_c = rand() % cont.size();
        auto it  = cont.begin();
        std::advance(it, i_c);
        return *it;
    }
}

