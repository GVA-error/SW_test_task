#pragma once

#include <unistd.h>
#include <cstdint>
#include <memory>

#include <IO/Commands/CreateMap.hpp>
#include <IO/Commands/Tick.h>
#include <IO/Commands/March.hpp>
#include <IO/Commands/SpawnHunter.hpp>
#include <IO/Commands/SpawnSwordsman.hpp>
#include <IO/System/EventLog.hpp>

#include "Entities/UnitsHeap.hpp"
#include "Entities/GameField.hpp"
#include "Utils/MoveOrder.hpp"
#include "AI/AI_TurnPreparation.hpp"
#include "AI/AI_UnitSpawner.hpp"
#include "AI/AI_TurnMaster.hpp"
#include "AI/AI_General.hpp"

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
        virtual ~Simulation() {};

        // Состояние симуляции на моммент последнего тика
        SimulationStatus getSimulationStatus() const;

        // Командный интерфейс симуляции
        template <typename TCommand>
        void command(TCommand&) { eventLog.log(currentTick, sw::io::Error("Simulation::command type not found.")); }
        void command(sw::io::CreateMap&);
        void command(sw::io::Tick&);
        void command(sw::io::March&);
        void command(sw::io::SpawnHunter&);
        void command(sw::io::SpawnSwordsman&);

    private:
        uint32_t currentTick = 0;
        sw::EventLog eventLog;
        SimulationStatus simulationStatus;

        // Крупные программные сущности
        // поле, очередь ходов и куча используються различными AI
        // Являются частью симуляции. Поэтому создаются в ней.
        std::shared_ptr<entities::UnitHeap>  unitsHeap;
        std::shared_ptr<entities::MoveOrder> moveOrder;
        std::shared_ptr<entities::GameField> gameField;

        // Очистка поля от тел и прочие подготовки для хода
        std::shared_ptr<AI::AI_TurnPraparation>   turnPreparationAI;
        // Создаёт юнитов на куче и поле. Добавляет их в очередь хода
        std::shared_ptr<AI::AI_UnitSpawner>       unitSpawnerAI;
        // Отдаёт команды юнитам
        std::shared_ptr<AI::AI_General>           generalAI;
        // Контролирует AI юнитов во время хода
        std::shared_ptr<AI::AI_TurnMaster>        turnMasterAI;

        // Обобщённое поведение создания юнита
        // Создаёт как самого юнита, так и соответствующие бекэнды
        // Добавляет его в очередь хода.
        // UnitAI - искуственный интелект юнита. Наследник AI::AI.
        template <class UnitAI, typename TCommand>
        void spawnCommand(TCommand& command)
        {
            bool f_success = unitSpawnerAI->spawn(gameField, currentTick, command);
            if (f_success)
                turnMasterAI->setUnitAI<UnitAI>(command.unitId, gameField);
        }
    };
}

