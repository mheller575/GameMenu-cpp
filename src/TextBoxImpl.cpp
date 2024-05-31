#include "TextBoxImpl.h"

namespace Menu
{
	sf::RectangleShape BuildRectangle(const sf::Vector2f& position, const TextBoxStyle& style);
	sf::Text BuildText(const sf::Vector2f& position, const TextBoxStyle& style, const std::string& text);

	ITextBox::~ITextBox() {}
	
	ITextBox::ITextBox() {}

	TextBoxImpl::TextBoxImpl(const std::string& text, const sf::Vector2f& position, const TextBoxStyle& style)
		: _style(style)
		, _textString(text)
		, _rectangle(BuildRectangle(position, style))
		, _text(BuildText(position, style, text))
		, _cursorPosition(text.size())
	{}

	TextBoxImpl::~TextBoxImpl() {}

	void TextBoxImpl::Draw(sf::RenderTarget* window)
	{
		// TODO: Handle updating for is active here with flashing cursor.

		window->draw(_rectangle);
		window->draw(_text);
	}

	void TextBoxImpl::HandleEvent(const sf::Event& event, sf::RenderTarget* window)
	{
		if (event.type == sf::Event::EventType::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
		{
			if (_rectangle.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				if (_selected)
				{
					// TODO: Handle moving the cursor to the new text position.
				}
				else 
				{
					_selected = true;

					std::string localTextCopy = _textString;

					localTextCopy.insert(_cursorPosition, CursorCharacter);
					_text.setString(localTextCopy);
				}
			}
		}
	}

	sf::RectangleShape BuildRectangle(const sf::Vector2f& position, const TextBoxStyle& style)
	{
		sf::RectangleShape rectangle(style.TextBoxSize);

		rectangle.setFillColor(style.BackgroundColor);
		rectangle.setOutlineColor(style.BorderColor);
		rectangle.setOutlineThickness(style.BorderThickness);
		
		return rectangle;
	}

	sf::Text BuildText(const sf::Vector2f& position, const TextBoxStyle& style, const std::string& text)
	{
		sf::Text sfText(text, style.TextStyle.Font, style.TextStyle.FontSize);

		sfText.setColor(style.TextStyle.Color);
		sfText.setPosition(sf::Vector2f(position.x + style.BorderThickness, position.y + style.BorderThickness));
		
		return sfText;
	}
}