#include "simulation.h"


namespace sw
{

    Simulation::Simulation() {}

    Simulation::SimulationStatus Simulation::tick()
    {
        SimulationStatus stat;
        stat.tick = currentTick;


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
        auto w = ;
        auto h = ;
        auto unitX = ;
        auto unitY = ;

        bool f_outOfMap = false;
        f_outOfMap |= targetX < 0;
        f_outOfMap |= targetY < 0;
        f_outOfMap |= targetX >= w;
        f_outOfMap |= targetY >= h;

        if (f_outOfMap)
        {
            eventLog.log(currentTick, sw::io::Error("Simulation::March incorrect position."));
            return;
        }

        eventLog.log(currentTick, io::MarchStarted{unitId, unitX, unitY, targetX, targetY});
    }
    void Simulation::command(sw::io::SpawnHunter&)
    {

    }
    void Simulation::command(sw::io::SpawnSwordsman&)
    {

    }

}
