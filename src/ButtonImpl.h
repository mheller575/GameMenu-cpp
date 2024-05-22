#pragma once

#include <functional>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "IButton.h"
#include "ILogger.h"
#include "SubscriptionManager.h"

namespace Menu
{
	class ButtonImpl : public IButton
	{
	public:
		ButtonImpl(const sf::Vector2f& position, const ButtonStyle& config,	const std::shared_ptr<ISubscriptionManager>& pressDownSM, 
			const std::shared_ptr<ISubscriptionManager>& releaseSM);
		virtual ~ButtonImpl();

		void Draw(sf::RenderTarget* window) const override;
		void HandleEvent(const sf::Event& event, sf::RenderTarget* window) override;

		virtual UnsubscribeHandler SubscribeToOnPressedDown(const std::function<void()>& handler) override;
		virtual UnsubscribeHandler SubscribeToOnPressedUp(const std::function<void()>& handler) override;

	private:
		const std::shared_ptr<ISubscriptionManager> onPressedDown_;
		const std::shared_ptr<ISubscriptionManager> onReleasedUp_;

		std::shared_ptr<ILogger> logger_;
		ButtonStyle _style;
		sf::RectangleShape _buttonBody;
		sf::Text _buttonText;
	};
}
