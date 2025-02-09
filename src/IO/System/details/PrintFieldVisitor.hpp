#pragma once

#include <iostream>

namespace sw
{
	class PrintFieldVisitor
	{
	private:
		std::ostream& _stream;

	public:
		explicit PrintFieldVisitor(std::ostream& stream) :
				_stream(stream)
		{}

		template <typename T>
		void visit(const char* name, const T& value)
		{
			_stream << name << "=" << value << ' ';
		}
	};

}
