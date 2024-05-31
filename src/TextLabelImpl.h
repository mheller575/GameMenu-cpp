#pragma once

#include "ITextLabel.h"

namespace Menu
{
	class TextLabelImpl : public ITextLabel
	{
	public:
		TextLabelImpl(const std::string& text, const sf::Vector2f& position, const TextLabelStyle& style);
		virtual ~TextLabelImpl();

		void Draw(sf::RenderTarget* window) override;
		void HandleEvent(const sf::Event& event, sf::RenderTarget* window) override;

	private:
		//std::shared_ptr<ILogger> logger_;
		TextLabelStyle _style;
		sf::Text _text;
	};
}