#ifndef SIMULATION_H
#define SIMULATION_H

#include <cstdint>
#include <memory>
#include <IO/Commands/CreateMap.hpp>
#include <IO/Commands/March.hpp>
#include <IO/Commands/SpawnHunter.hpp>
#include <IO/Commands/SpawnSwordsman.hpp>
#include <IO/System/EventLog.hpp>
#include <IO/Events/Error.hpp>
#include <IO/Events/MapCreated.hpp>
#include <IO/Events/MarchEnded.hpp>
#include <IO/Events/MarchStarted.hpp>
#include <IO/Events/UnitAttacked.hpp>
#include <IO/Events/UnitDied.hpp>
#include <IO/Events/UnitMoved.hpp>
#include <IO/Events/UnitSpawned.hpp>

#include "entities/gamefield.h"
#include "mechanics/Spawn.h"

namespace sw
{
/*
 * Симулирует игровой процесс c помощью Simulation::tick.
*/
    class Simulation
    {
    public:
        // Структура для возврата состояния симуляции после тика
        struct SimulationStatus
        {
            int tick;       // Просимулированный тик
            bool isFinished;// Закончена ли симуляции.
        };

        Simulation();
        SimulationStatus tick();

        // Комады инициализации
        // Интерфейс для CommandParser::add
        template <typename TCommand>
        void command(TCommand&) { eventLog.log(currentTick, sw::io::Error("Simulation::command type not found.")); }
        void command(sw::io::CreateMap&);
        void command(sw::io::March&);
        void command(sw::io::SpawnHunter&);
        void command(sw::io::SpawnSwordsman&);

    private:
        uint32_t currentTick = 0;
        sw::EventLog eventLog;
        std::shared_ptr<sw::entities::GameField> gameField;
        // очерёдность ходов
        std::list<uint32_t> moveOrder;
        std::map<uint32_t, sw::entities::Unit> unitsHeap;

        // События начала хода
        void turtStart();
        // Исполнение механик хода юнитами.
        // Возвращает было ли совершено какое либо действие юнитами.
        bool turt();
        // События конца хода
        void turtFinish();

        template <typename TCommand>
        void spawnCommand(TCommand& command)
        {
            if (unitsHeap.find(command.unitId) != unitsHeap.end())
            {
                eventLog.log(currentTick, sw::io::Error("Simulation::spawnCommand trying to recreate unit with same id."));
                return;
            }
            auto unit = sw::mechanics::spawn::Spawn(gameField, command);
            if (unit.isCorrect() == false)
            {
                eventLog.log(currentTick, sw::io::Error("Simulation::spawnCommand can not spawn on this position."));
                return;
            }
            moveOrder.push_back(unit.getId());
            unitsHeap[unit.getId()] = unit;
        }
    };
}
    #endif // SIMULATION_H
