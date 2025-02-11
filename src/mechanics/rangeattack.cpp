#include "rangeattack.h"


namespace sw::mechanics
{

    using namespace sw::entities;
    bool tryToRandomRangeAttack(std::shared_ptr<sw::entities::GameField>& gf, sw::entities::Unit& u, UnitAttributes& DAMAGE_STAT, uint32_t& out_attackedUnit)
    {
        bool f_activity = false;
        out_attackedUnit = UNDEFINED_UNIT_ID;

        return f_activity;
    }
}
