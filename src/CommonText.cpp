
#include "CommonText.h"

namespace Menu
{
	sf::Vector2f GetTextPosition(const sf::FloatRect& containerSize, const sf::FloatRect& textSize, const Padding& textPadding,
		const HorizontalAlignment& horizontal, const VerticalAlignment& vertical, const sf::Vector2f& overallPosition)
	{
		float y = textPadding.Top;
		if (vertical == VerticalAlignment::Bottom)
		{
			y = containerSize.height - (textPadding.Bottom + textSize.height);
		}
		else if (vertical == VerticalAlignment::Center)
		{
			const auto halfOverallTextHeight = (textSize.height + textPadding.Top + textPadding.Bottom) / 2.0f;
			const auto containerVerticalMidpoint = (float)containerSize.height / 2.0f;
			y = (containerVerticalMidpoint - halfOverallTextHeight) + textPadding.Top;
		}

		float x = textPadding.Left;
		if (horizontal == HorizontalAlignment::Right)
		{
			x = containerSize.width - (textSize.width + textPadding.Right);
		}
		else if (horizontal == HorizontalAlignment::Center)
		{
			const auto halfOverallTextWidth = (textPadding.Left + textSize.width + textPadding.Right) / 2.0f;
			const auto containerHorizontalMidpoint = (containerSize.width / 2.0f);
			x = (containerHorizontalMidpoint - halfOverallTextWidth) + textPadding.Left;
		}

		return sf::Vector2f(overallPosition.x + x, overallPosition.y + y);
	}
}
