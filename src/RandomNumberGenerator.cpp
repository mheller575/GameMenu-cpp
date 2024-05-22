
#include <random>

#include "RandomNumberGenerator.h"

namespace Menu
{
	static std::random_device rd;
	static std::mt19937 rng{ rd() };

	std::int32_t GetRandomNumber(const std::int32_t& min, const std::int32_t& max)
	{
		std::uniform_int_distribution<std::int32_t> gen(min, max);
		return gen(rng);
	}
}