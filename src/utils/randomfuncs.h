#ifndef RANDOMFUNCS_H
#define RANDOMFUNCS_H

#include <cstdint>
#include <cstdlib>
#include <iterator>

namespace sw::utils
{
    template <class CONTAINER>
    auto randomChoice(const CONTAINER& cont)
    {
        auto i_c = rand() % cont.size();
        auto it  = cont.begin();
        std::advance(it, i_c);
        return *it;
    }
}

#endif // RANDOMFUNCS_H
