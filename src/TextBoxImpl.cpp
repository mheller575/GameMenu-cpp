#include "TextBoxImpl.h"

namespace Menu
{
	const char BackspaceCharacterUnicode = '\b';

	sf::RectangleShape BuildRectangle(const sf::Vector2f& position, const TextBoxStyle& style);
	sf::Text BuildText(const sf::Vector2f& position, const TextBoxStyle& style, const std::string& text);

	ITextBox::~ITextBox() {}
	
	ITextBox::ITextBox() {}

	TextBoxImpl::TextBoxImpl(const std::string& text, const sf::Vector2f& position, const TextBoxStyle& style)
		: _style(style)
		, _textString(text)
		, _textBoxBackground(BuildRectangle(position, style))
		, _text(BuildText(position, style, text))
	{
		//_cursor = BuildRectangle()
	}

	TextBoxImpl::~TextBoxImpl() {}

	void TextBoxImpl::Draw(sf::RenderTarget* window)
	{
		if (_selected)
		{
			//const auto charSize = _text.getCharacterSize();
			//const auto charSpacing = _text.getLetterSpacing();
			//
			//const auto cursorXPosition = _text.getPosition().x + (_textString.size() * charSize);
			//const auto cursorYPosition = _text.getPosition().y;
		}

		window->draw(_textBoxBackground);
		window->draw(_text);
	}

	void TextBoxImpl::HandleEvent(const sf::Event& event, sf::RenderTarget* window)
	{
		if (event.type == sf::Event::EventType::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
		{
			if (_textBoxBackground.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				if (_selected)
				{
					// TODO: Handle moving the cursor to the new text position.
				}
				else 
				{
					_selected = true;
				}
			}
			else
			{
				_selected = false;
			}
		}

		if (_selected)
		{
			if (event.type == sf::Event::EventType::TextEntered)
			{
				const auto textEntered = static_cast<char>(event.text.unicode);

				if (textEntered == BackspaceCharacterUnicode)
				{
					if (_textString.length() != 0)
					{
						_textString = _textString.substr(0, _textString.length() - 1);
					}
				}
				else
				{
					_textString += textEntered;
				}

				_text.setString(_textString);
			}
		}
	}

	sf::RectangleShape BuildRectangle(const sf::Vector2f& position, const TextBoxStyle& style)
	{
		sf::RectangleShape rectangle(style.TextBoxSize);

		rectangle.setFillColor(style.BackgroundColor);
		rectangle.setOutlineColor(style.BorderColor);
		rectangle.setOutlineThickness(style.BorderThickness);
		rectangle.setPosition(position);

		return rectangle;
	}

	sf::Text BuildText(const sf::Vector2f& position, const TextBoxStyle& style, const std::string& text)
	{
		sf::Text sfText(text, style.TextStyle.Font, style.TextStyle.FontSize);

		sfText.setColor(style.TextStyle.Color);
		sfText.setPosition(sf::Vector2f(position.x + style.BorderThickness, position.y + style.BorderThickness));
		
		return sfText;
	}

	std::shared_ptr<ITextBox> BuildTextBox(const std::string& text, const TextBoxStyle& style, const sf::Vector2f& position)
	{
		return std::make_shared<TextBoxImpl>(text, position, style);
	}
}