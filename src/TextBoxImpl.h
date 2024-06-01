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
		const std::uint64_t _cursorFlashRate_ms = 400;

		TextBoxStyle _style;
		sf::Text _text;
		sf::RectangleShape _textBoxBackground;
		sf::RectangleShape _cursor;

		std::string _textString;
		bool _selected = false;
		std::uint64_t _lastCursorStateChangeTime_ms = 0;
		bool _showCursor = false;
	};
}