
#include "TextLabelImpl.h"

namespace Menu
{
	sf::Text BuildText(const std::string& text, const sf::Vector2f& position, const TextLabelStyle& style);

	ITextLabel::~ITextLabel() {}

	ITextLabel::ITextLabel() {}

	std::shared_ptr<ITextLabel> BuildTextLabel(const std::string& text, const sf::Vector2f& position, const TextLabelStyle& textLabelStyle)
	{
		return std::make_shared<TextLabelImpl>(text, position, textLabelStyle);
	}

	TextLabelImpl::TextLabelImpl(const std::string& text, const sf::Vector2f& position, const TextLabelStyle& style)
		: _style(style)
		, _text(BuildText(text, position, style))
	{}

	TextLabelImpl::~TextLabelImpl() {}

	void TextLabelImpl::Draw(sf::RenderTarget* window)
	{
		window->draw(_text);
	}

	void TextLabelImpl::HandleEvent(const sf::Event& event, sf::RenderTarget* window)
	{
		// No events to handle.
	}

	sf::Text BuildText(const std::string& text, const sf::Vector2f& position, const TextLabelStyle& style)
	{
		sf::Text sfText(text, style.Font, style.FontSize);
		sfText.setColor(style.Color);
		sfText.setPosition(position);
		
		return sfText;
	}
}