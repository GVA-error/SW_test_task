#pragma once

#include "details/PrintFieldVisitor.hpp"
#include "IO/Events/Error.hpp"
#include <iostream>
#include <cstdint>
#include <typeindex>
#include <unordered_map>

namespace sw
{
	class EventLog
	{
	public:
		template <class TEvent>
		void log(uint64_t tick, TEvent&& event)
		{
			std::cout << "[" << tick << "] " << TEvent::Name << " ";
			PrintFieldVisitor visitor(std::cout);
			event.visit(visitor);
			std::cout << std::endl;
		}

        /*
        // Особый вывод ошибок или их запрет.
        void log(uint64_t tick, sw::io::Error&& event)
        {

        }
        */
	};
}
