#pragma once

#include <SFML/Graphics.hpp>

#include "CommonStructures.h"

namespace Menu
{
	sf::Vector2f GetTextPosition(const sf::FloatRect& containerSize, const sf::FloatRect& textSize,	const HorizontalAlignment& horizontal, 
		const VerticalAlignment& vertical, const sf::Vector2f& overallPosition);
}