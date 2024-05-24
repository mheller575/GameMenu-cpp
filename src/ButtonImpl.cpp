#include "CommonStructures.h"
#include "IButton.h"
#include "ILogger.h"
#include "ButtonImpl.h"

namespace Menu
{
	sf::Text BuildText(const std::string& text, const TextStyle& style, const sf::FloatRect& containerSize, const sf::Vector2f& overallPosition);
	sf::RectangleShape BuildRectangle(const sf::Vector2f& size, const sf::Color& unpressedColor, const sf::Color& borderColor, const float& borderThickness, const sf::Vector2f& position);

	IButton::IButton() {}

	IButton::~IButton() {}

	std::shared_ptr<IButton> BuildButton(const sf::Vector2f& position, const ButtonStyle& buttonConfig)
	{
		const auto pressedDownSM = BuildSubscriptionManager();
		const auto releasedSM = BuildSubscriptionManager();

		return std::make_shared<ButtonImpl>(position, buttonConfig, pressedDownSM, releasedSM);
	}

	ButtonImpl::ButtonImpl(const sf::Vector2f& position, const ButtonStyle& config, const std::shared_ptr<ISubscriptionManager>& pressDownSM,
		const std::shared_ptr<ISubscriptionManager>& releaseSM)
		: _style(config)
		, onPressedDown_(pressDownSM)
		, onReleasedUp_(releaseSM)
	{
		_buttonBody = BuildRectangle(config.ButtonSize, config.UnpressedColor, config.BorderColor, config.ButtonBorderThickness, position);
		_buttonText = BuildText(config.Text, config.TextStyle, _buttonBody.getLocalBounds(), position);
	}

	ButtonImpl::~ButtonImpl() {}

	void ButtonImpl::Draw(sf::RenderTarget* window) const
	{
		window->draw(_buttonBody);
		window->draw(_buttonText);
	}

	void ButtonImpl::HandleEvent(const sf::Event& event, sf::RenderTarget* window)
	{
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
		{
			sf::Vector2f mouseClickPosition(event.mouseButton.x, event.mouseButton.y);
			if (_buttonBody.getGlobalBounds().contains(mouseClickPosition))
			{
				_buttonBody.setFillColor(_style.PressedColor);
				onPressedDown_->CallCallbacks();
			}
		}
		else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Button::Left)
		{
			sf::Vector2f mouseClickPosition(event.mouseButton.x, event.mouseButton.y);
			if (_buttonBody.getGlobalBounds().contains(mouseClickPosition))
			{
				_buttonBody.setFillColor(_style.UnpressedColor);
				onReleasedUp_->CallCallbacks();
			}
		}
	}

	UnsubscribeHandler ButtonImpl::SubscribeToOnPressedDown(const std::function<void()>& handler)
	{
		return onPressedDown_->Subscribe(handler);
	}

	UnsubscribeHandler ButtonImpl::SubscribeToOnPressedUp(const std::function<void()>& handler)
	{
		return onReleasedUp_->Subscribe(handler);
	}

	sf::Text BuildText(const std::string& text, const TextStyle& style, const sf::FloatRect& containerSize, const sf::Vector2f& overallPosition)
	{
		sf::Text sfText(text, style.Font, style.FontSize);
		const auto globalBounds = sfText.getGlobalBounds();
		const auto textPos = GetTextPosition(containerSize, globalBounds, style.Padding, style.HorizAlign, style.VertAlign, overallPosition);
		sfText.setPosition(textPos);
		sfText.setFillColor(style.Color);

		return sfText;
	}

	sf::RectangleShape BuildRectangle(const sf::Vector2f& size, const sf::Color& unpressedColor, const sf::Color& borderColor, const float& borderThickness, const sf::Vector2f& position)
	{
		sf::RectangleShape sfRect(size);

		sfRect.setFillColor(unpressedColor);
		sfRect.setOutlineColor(borderColor);
		sfRect.setOutlineThickness(borderThickness);
		sfRect.setPosition(position);

		return sfRect;
	}
}
