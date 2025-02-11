#include "ai_spawnswordsman.h"

namespace sw::AI
{
    using namespace sw::entities;

    AI_SpawnSwordsman::AI_SpawnSwordsman(std::shared_ptr<sw::entities::GameField>& gf)
        : AI(gf)
    {
    }

    bool AI_SpawnSwordsman::tick(sw::entities::Unit& u)
    {
        mechanics::tryToRandomMeleeAttack<UnitAttributes::Strength>(gf, u);

    }

}
