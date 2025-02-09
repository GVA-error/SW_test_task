#ifndef ERROR_H
#define ERROR_H

#include <string>

namespace sw::io
{
struct Error
{
    constexpr static const char* Name = "ERROR";

    std::string description{};

    template <typename Visitor>
    void visit(Visitor& visitor)
    {
        visitor.visit("description", description);
    }
};
}

#endif // ERROR_H
