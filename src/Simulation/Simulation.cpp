#include "Simulation.hpp"
#include "IO/Events/MapCreated.hpp"
#include "AI/Unit/AI_Swordsman.hpp"
#include "AI/Unit/AI_Hunter.hpp"

namespace sw
{
    Simulation::Simulation()
    {
        unitsHeap         = std::make_shared<entities::UnitHeap>();
        moveOrder         = std::make_shared<entities::MoveOrder>();
        turnPreparationAI = std::make_shared<AI::AI_TurnPraparation>(unitsHeap, moveOrder);
        turnMasterAI      = std::make_shared<AI::AI_TurnMaster>(unitsHeap, moveOrder);
        unitSpawnerAI     = std::make_shared<AI::AI_UnitSpawner>(unitsHeap, moveOrder);
        generalAI         = std::make_shared<AI::AI_General>(unitsHeap);
    }

    void Simulation::command(sw::io::Tick& tick)
    {
        simulationStatus.isFinished = false;
        simulationStatus.tick = currentTick;

        turnPreparationAI->orderPreparation(gameField);
        bool isActivityFound = turnMasterAI->tick(currentTick);
        if (isActivityFound)
            simulationStatus.isFinished = false;
        else
            simulationStatus.isFinished = true;
        turnPreparationAI->orderPostHandle(gameField);

        currentTick++;
    }

    Simulation::SimulationStatus Simulation::getSimulationStatus() const
    {
        return simulationStatus;
    }

    void Simulation::command(sw::io::CreateMap& command)
    {
        if (gameField != nullptr)
        {
            eventLog.log(currentTick, sw::io::Error("Simulation::CreateMap we try to create map twice."));
            return;
        }
        auto w = command.width;
        auto h = command.height;
        if (w <= 0 || h <= 0)
        {
            eventLog.log(currentTick, sw::io::Error("Simulation::CreateMap incorrect sizes."));
            return;
        }
        gameField = std::make_shared<sw::entities::GameField>(w, h);
        io::MapCreated mapCreatedEvent;
        mapCreatedEvent.width  = w;
        mapCreatedEvent.height = h;
        eventLog.log(currentTick, std::move(mapCreatedEvent));
    }

    void Simulation::command(sw::io::March& command)
    {
        auto unitId  = command.unitId;
        auto targetX = command.targetX;
        auto targetY = command.targetY;
        if (gameField == nullptr)
        {
            eventLog.log(currentTick, sw::io::Error("Simulation::March field is not created. Use Simulation::CreateMap before."));
            return;
        }
        generalAI->MARCH(currentTick, gameField, unitId, targetX, targetY);
    }

    void Simulation::command(sw::io::SpawnSwordsman& sm)
    {
        spawnCommand<AI::AI_Swordsman>(sm);
    }

    void Simulation::command(sw::io::SpawnHunter& h)
    {
        spawnCommand<AI::AI_Hunter>(h);
    }
}
