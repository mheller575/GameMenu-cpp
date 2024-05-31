#pragma once

#include <functional>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>

#include "CommonStructures.h"
#include "ITextLabel.h"
#include "IControl.h"
#include "SubscriptionManager.h"

namespace Menu
{
	/// <summary>
	/// Interface for a Button object.
	/// </summary>
	class IButton : public IControl
	{
	public:
		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~IButton();

		virtual UnsubscribeHandler SubscribeToOnPressedDown(const std::function<void()>& handler) = 0;

		virtual UnsubscribeHandler SubscribeToOnPressedUp(const std::function<void()>& handler) = 0;

	protected:
		IButton();
	};

	struct ButtonStyle
	{
		std::string Text;

		TextLabelStyle TextStyle;

		HorizontalAlignment TextHorizontalAlignment;

		VerticalAlignment TextVerticalAlignment;

		sf::Color UnpressedColor;

		sf::Color PressedColor;

		sf::Color BorderColor;

		sf::Vector2f ButtonSize;

		float ButtonBorderThickness = 0.0;
	};

	std::shared_ptr<IButton> BuildButton(const sf::Vector2f& position, const ButtonStyle& buttonConfig);
}
