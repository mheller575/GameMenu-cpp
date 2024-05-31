#pragma once

#include "ITextBox.h"

namespace Menu
{
	class TextBoxImpl : public ITextBox
	{
	public:
		TextBoxImpl(const std::string& text, const sf::Vector2f& position, const TextBoxStyle& style);
		virtual ~TextBoxImpl();

		void Draw(sf::RenderTarget* window) override;
		void HandleEvent(const sf::Event& event, sf::RenderTarget* window) override;

	private:
		const std::string CursorCharacter = "|";

		//std::shared_ptr<ILogger> logger_;
		TextBoxStyle _style;
		std::string _textString;
		sf::Text _text;
		sf::RectangleShape _rectangle;

		bool _selected = false;
		std::uint32_t _cursorPosition;
		std::uint32_t _firstVisibleCharacterIndex = 0;
	};
}