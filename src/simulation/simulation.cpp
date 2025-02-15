#include "simulation.h"

#include "AI/AI_Swordsman.h"
#include "AI/AI_Hunter.h"

namespace sw
{

    Simulation::Simulation()
    {
        unitsHeap = std::make_shared<entities::UnitHeap>();
        moveOrder = std::make_shared<entities::MoveOrder>();
        turnPreparationAI = std::make_shared<AI::AI_OrderPraparation>(unitsHeap, moveOrder);
        turnMasterAI      = std::make_shared<AI::AI_TurnMaster>(unitsHeap, moveOrder);
    }

    Simulation::SimulationStatus Simulation::tick()
    {
        SimulationStatus stat;
        stat.isFinished = false;
        stat.tick = currentTick;

        turnPreparationAI->orderPreparation(gameField);
        bool isActivityFound = turnMasterAI->tick(currentTick);
        if (isActivityFound)
            stat.isFinished = false;
        else
            stat.isFinished = true;
        turnPreparationAI->orderPostHandle(gameField);

        sleep(1);

        currentTick++;
        return stat;
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

        eventLog.log(currentTick, io::MapCreated{w, h});
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

        auto w = gameField->getWidth();
        auto h = gameField->getHeight();

        auto unitPos = gameField->getUnitPosition(unitId);
        if (unitPos == utils::UNDEFINED_POSITION)
        {
            eventLog.log(currentTick, sw::io::Error("Simulation::March field is not created. Use Simulation::CreateMap before."));
            return;
        }

        bool f_outOfMap = false;
        f_outOfMap |= targetX < 0;
        f_outOfMap |= targetY < 0;
        f_outOfMap |= targetX >= w;
        f_outOfMap |= targetY >= h;

        if (f_outOfMap)
        {
            eventLog.log(currentTick, sw::io::Error("Simulation::March incorrect position. Target is out of map."));
            return;
        }

        gameField->March(unitId, targetX, targetY);
        eventLog.log(currentTick, io::MarchStarted{unitId, unitPos.x, unitPos.y, targetX, targetY});
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
