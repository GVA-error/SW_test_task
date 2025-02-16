#pragma once

#include <cstdint>

namespace sw::io
{
    struct Tick
    {
        constexpr static const char* Name = "TICK_SIMULATION";

        template <typename Visitor>
        void visit(Visitor& visitor)
        {
        }
    };
}
