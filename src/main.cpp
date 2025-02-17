#include <fstream>
#include <iostream>

#include <IO/Commands/CreateMap.hpp>
#include <IO/Commands/March.hpp>
#include <IO/Commands/SpawnHunter.hpp>
#include <IO/Commands/SpawnSwordsman.hpp>
#include <IO/Commands/Tick.h>
#include <IO/System/CommandParser.hpp>
#include <IO/System/EventLog.hpp>
#include <IO/System/PrintDebug.hpp>

#include "Simulation/Simulation.hpp"

int main(int argc, char** argv)
{
	using namespace sw;
    // В решении используется rand()
    // Поэтому для детерминированности используем фиксированный сид.
    std::srand(42);

    if (argc != 2)
	{
		throw std::runtime_error("Error: No file specified in command line argument");
	}
	std::ifstream file(argv[1]);

    if (!file)
	{
		throw std::runtime_error("Error: File not found - " + std::string(argv[1]));
	}

    Simulation simulation;
    io::CommandParser parser;
    auto simulationParse = [&](auto command) {
        simulation.command(command);
    };

    parser.add<io::CreateMap>(simulationParse)
        .add<io::SpawnSwordsman>(simulationParse)
        .add<io::SpawnHunter>(simulationParse)
        .add<io::March>(simulationParse);

	parser.parse(file);

    while (true)
    {
        sw::io::Tick tickCommand;
        simulation.command(tickCommand);
        auto status = simulation.getSimulationStatus();
        if (status.isFinished)
            break;
        //sleep(1);
    }

	return 0;
}
