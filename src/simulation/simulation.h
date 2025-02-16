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
#include "AI/AI_OrderPreparation.h"
#include "AI/ai_TurnMaster.h"
#include "AI/AI_UnitSpawner.h"

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

        // Очистка поля от тел и прочие подготовки для хода
        std::shared_ptr<AI::AI_OrderPraparation> turnPreparationAI;
        // Контролирует другие AI во время хода
        std::shared_ptr<AI::AI_TurnMaster>       turnMasterAI;
        // Создаёт юнитов на куче и поле. Добавляет их в очередь хода
        std::shared_ptr<AI::AI_UnitSpawner>       unitSpawnerAI;

        // Обобщённое поведение создания юнита
        // Создаёт как самого юнита, так и соответствующие бекэнды
        // Добавляет его в очередь хода.
        // UnitAI - искуственный интелект юнита. Наследник AI::AI.
        template <class UnitAI, typename TCommand>
        void spawnCommand(TCommand& command)
        {
            unitSpawnerAI->spawn(gameField, currentTick, command);
            turnMasterAI->setUnitAI<UnitAI>(command.unitId, gameField);
        }
    };
}
    #endif // SIMULATION_H
