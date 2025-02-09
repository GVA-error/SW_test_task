#pragma once

#include "details/CommandParserVisitor.hpp"

#include <functional>
#include <sstream>
#include <string>

namespace sw::io
{
	class CommandParser
	{
	private:
		std::unordered_map<std::string, std::function<void(std::istream&)>> _commands;

	public:
		template <class TCommandData>
		CommandParser& add(std::function<void(TCommandData)> handler)
		{
			std::string commandName = TCommandData::Name;
			auto [it, inserted] = _commands.emplace(
				commandName,
				[handler = std::move(handler)](std::istream& stream)
				{
					TCommandData data;
					CommandParserVisitor visitor(stream);
					data.visit(visitor);
					handler(std::move(data));
				});
			if (!inserted)
			{
				throw std::runtime_error("Command already exists: " + commandName);
			}

			return *this;
		}

		void parse(std::istream& stream);
	};
}
