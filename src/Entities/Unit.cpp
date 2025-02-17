#include "Unit.hpp"

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

    bool Unit::isDead() const
    {
        return getCurrentHP() == 0;
    }

    int32_t Unit::getCurrentHP() const
    {
        return status.at(UnitStatus::HP);
    }

    void Unit::takeDamage(int32_t damageHpImpact)
    {
        auto curHp = getCurrentHP();
        if (curHp <= damageHpImpact)
            set(UnitStatus::HP, 0);
        else
            set(UnitStatus::HP, curHp-damageHpImpact);
    }

}
