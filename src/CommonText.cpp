
#include "CommonText.h"

namespace Menu
{
	sf::Vector2f GetTextPosition(const sf::FloatRect& containerSize, const sf::FloatRect& textSize,	const HorizontalAlignment& horizontal, 
		const VerticalAlignment& vertical, const sf::Vector2f& overallPosition)
	{
		float y = 0.0;
		if (vertical == VerticalAlignment::Bottom)
		{
			y = containerSize.height - textSize.height;
		}
		else if (vertical == VerticalAlignment::Center)
		{
			y = ((containerSize.height - textSize.height) / 2.0) - 8.0;
		}

		float x = 0.0;
		if (horizontal == HorizontalAlignment::Right)
		{
			x = containerSize.width - textSize.width;
		}
		else if (horizontal == HorizontalAlignment::Center)
		{
			x = ((containerSize.width - textSize.width) / 2.0f) - 4.0;
		}

		return sf::Vector2f(overallPosition.x + x, overallPosition.y + y);
	}
}
