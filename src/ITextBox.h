#pragma once

#include "IControl.h"
#include "ITextLabel.h"

namespace Menu
{
	/// <summary>
	/// Interface for a Text Box object.
	/// </summary>
	class ITextBox : public IControl
	{
	public:
		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~ITextBox();

	protected:
		ITextBox();
	};

	struct TextBoxStyle
	{
		sf::Color BackgroundColor;

		sf::Color BorderColor;

		float BorderThickness = 0.0;
		
		sf::Vector2f TextBoxSize;

		TextLabelStyle TextStyle;
	};

	std::shared_ptr<ITextBox> BuildTextBox(const std::string& text, const TextBoxStyle& style, const sf::Vector2f& position);
}