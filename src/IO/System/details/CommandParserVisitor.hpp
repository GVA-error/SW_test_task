#pragma once

#include <iostream>

namespace sw
{
	class CommandParserVisitor
	{
	private:
		std::istream& _stream;

	public:
		CommandParserVisitor(std::istream& stream) :
				_stream(stream)
		{}

		template <class TField>
		void visit(const char*, TField& field)
		{
			_stream >> field;
		}
	};
}
