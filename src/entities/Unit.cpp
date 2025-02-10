#include "Unit.h"

namespace sw::entities
{

    Unit::Unit(uint32_t _id, const std::string& _typeName)
        :id(_id), typeName(_typeName)
    {

    }

    const std::string Unit::getTypeName() const
    {
        return typeName;
    }

    const uint32_t Unit::getId() const
    {
        return id;
    }


    bool Unit::isCorrect() const
    {
        return f_isCorrect;
    }

    void Unit::markAsIncorrect()
    {
        f_isCorrect = true;
    }
}
