#pragma once

#include "details/PrintFieldVisitor.hpp"

namespace sw
{
	template <typename TCommand>
	void printDebug(std::ostream& stream, TCommand& data)
	{
		stream << data.Name << ' ';
		PrintFieldVisitor visitor(stream);
		data.visit(visitor);
		stream << "\n";
	}
}
