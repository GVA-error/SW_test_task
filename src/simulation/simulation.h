#ifndef SIMULATION_H
#define SIMULATION_H

#include <unistd.h>
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
#include "entities/unitsheap.h"
#include "utils/MoveOrder.h"
#include "mechanics/Spawn.h"
#include "AI/ai.h"

namespace sw
{
/*
 * Медиатор. Реагирует на команды действиями AI* координитруя их.
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

        // юниты, очередь и куча используються AI
        std::shared_ptr<entities::UnitHeap>  unitsHeap;
        std::shared_ptr<entities::GameField> gameField;
        std::shared_ptr<entities::MoveOrder> moveOrder;

        // искуственный интеллект юнита
        std::map<uint32_t, std::unique_ptr<AI::AI>> unitAI;

        // События начала хода
        void turtStart();

        // Исполнение механик хода юнитами.
        // Возвращает было ли совершено какое либо действие юнитами.
        bool turn();

        // .. юнитом
        bool turn(uint32_t unitId);
        bool turn(sw::entities::Unit&);

        // События конца хода
        void turtFinish();

        // Обобщённое поведение создания юнита
        // Создаёт как самого юнита, так и соответствующие бекэнды
        // Добавляет его в очередь хода.
        // UnitAI - искуственный интелект юнита. Наследник AI::AI.
        template <class UnitAI, typename TCommand>
        void spawnCommand(TCommand& command)
        {
            if (unitsHeap->contains(command.unitId))
            {
                eventLog.log(currentTick, sw::io::Error("Simulation::spawnCommand trying to recreate unit with same id."));
                return;
            }
            auto res = sw::mechanics::Spawn(gameField, unitsHeap, command);
            if (res.f_isCorrect == false)
            {
                auto logMess = "Simulation::spawnCommand can not spawn by this command. Reason: " + res.incorrectnessReason;
                eventLog.log(currentTick, sw::io::Error(logMess));
                return;
            }
            moveOrder->push(command.unitId);
            setUnitAI<UnitAI>(command.unitId);
        }

        // Устанавливаем AI для юнита
        template <class UnitAI>
        void setUnitAI(uint32_t unitId)
        {
            unitAI[unitId] = std::make_unique<UnitAI>(gameField, unitsHeap);
        }
    };
}
    #endif // SIMULATION_H
