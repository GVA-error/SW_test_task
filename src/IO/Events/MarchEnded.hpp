#pragma once

#include <cstdint>

namespace sw::io
{
	struct MarchEnded
	{
		constexpr static const char* Name = "MARCH_ENDED";

		uint32_t unitId{};
		uint32_t x{};
		uint32_t y{};

		template <typename Visitor>
		void visit(Visitor& visitor)
		{
			visitor.visit("unitId", unitId);
			visitor.visit("x", x);
			visitor.visit("y", y);
		}
	};
}
