#include "CommandParser.hpp"

namespace sw::io
{
	void CommandParser::parse(std::istream& stream)
	{
		std::string line;
		while (std::getline(stream, line))
		{
			if (line.rfind("//", 0) == 0 || line.empty())
			{
				continue;
			}

			std::istringstream commandStream(line);
			std::string commandName;
			commandStream >> commandName;

			if (commandName.empty())
			{
				continue;
			}

			auto command = _commands.find(commandName);
			if (command == _commands.end())
			{
				throw std::runtime_error("Unknown command: " + commandName);
			}

			command->second(commandStream);
		}
	}
}
