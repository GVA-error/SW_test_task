#include "pai_rangeattack.h"

#include "mechanics/rangeattack.h"
#include "AI/primitives/pai_defaultattacklog.h"

namespace sw::AI::primitive
{
    using namespace sw::entities;
    bool pAI_tryToRangeAttack(std::shared_ptr<GameField> &gf, std::shared_ptr<UnitHeap>& uh, Unit &u,
                              uint32_t tickNumber, sw::EventLog& eventLog, UnitAttributes DAMAGE_STAT)
    {
        // Пробуем атаковать
        auto attackRes = mechanics::tryToRandomRangeAttack(gf, uh, u, DAMAGE_STAT);
        pAI_AttackLog(u, attackRes, tickNumber, eventLog);
        return attackRes.f_activity;
    }
}
