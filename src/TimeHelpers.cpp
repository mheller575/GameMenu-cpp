#include <chrono>

#include "TimeHelpers.h"

namespace Menu
{
	std::uint64_t GetCurrentTimeSinceEpoch_ms()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	}
}