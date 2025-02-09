#pragma once

#include <cstdint>

namespace sw::io
{
	struct MapCreated
	{
		constexpr static const char* Name = "MAP_CREATED";

		uint32_t width{};
		uint32_t height{};

		template <typename Visitor>
		void visit(Visitor& visitor)
		{
			visitor.visit("width", width);
			visitor.visit("height", height);
		}
	};
}
