#pragma once

#include <memory>

#include <IO/System/EventLog.hpp>
#include <IO/System/EventLog.hpp>

#include "Entities/UnitsHeap.hpp"
#include "Entities/GameField.hpp"
#include "Mechanics/Spawn.hpp"
#include "AI/Unit/Primitives/pAI_SpawnLog.hpp"

// Описывем как АИ использует механики спавна
namespace sw::AI::primitive
{
    using namespace sw::entities;

    template <class TCommand>
    bool pAI_tryToSpawn(std::shared_ptr<GameField>& gf, std::shared_ptr<UnitHeap>& uh,
                        TCommand& command, uint32_t tickNumber, sw::EventLog& eventLog)
    {
        auto res = sw::mechanics::Spawn(gf, uh, command);
        pAI_SpawnLog(res, tickNumber, eventLog);
        return true;
    }
}
