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

    std::string Unit::getIncorrectnessReason() const
    {
        return incorrectnessReason;
    }

    void Unit::markAsIncorrect(const std::string& reason)
    {
        f_isCorrect = true;
        incorrectnessReason = reason;
    }
}
