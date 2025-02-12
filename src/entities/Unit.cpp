#include "Unit.h"

namespace sw::entities
{

    Unit::Unit(uint32_t id, const std::string& name)
        :id(id), name(name)
    {

    }

    const std::string Unit::getName() const
    {
        return name;
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

    bool Unit::isAllowed(const UnitMechanic& m) const
    {
        return mechanic.at(m);
    }

    int32_t Unit::getAttribute(const UnitAttributes& a) const
    {
        return attributes.at(a);
    }

    int32_t Unit::getState(const UnitStatus& s) const
    {
        return status.at(s);
    }

    int32_t Unit::is(const UnitType& t) const
    {
        return type.at(t);
    }

    void Unit::set(const UnitMechanic& m, bool f)
    {
        mechanic[m] = f;
    }

    void Unit::set(const UnitAttributes& a, int32_t value)
    {
        attributes[a] = value;
    }

    void Unit::set(const UnitStatus& s, int32_t value)
    {
        status[s] = value;
    }

    void Unit::set(const UnitType& t)
    {
        type[t] = true;
    }

}
