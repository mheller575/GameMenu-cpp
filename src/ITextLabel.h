
#pragma once

#include "IControl.h"

namespace Menu
{
	/// <summary>
	/// Interface for a text label object.
	/// </summary>
	class ITextLabel : public IControl
	{
	public:
		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~ITextLabel();

	protected:
		ITextLabel();
	};

	/// <summary>
	/// Defines the style for a text label style.
	/// </summary>
	struct TextLabelStyle
	{
		/// <summary>
		/// Color to apply to text.
		/// </summary>
		sf::Color Color;

		/// <summary>
		/// Font to apply to text.
		/// </summary>
		sf::Font Font;

		/// <summary>
		/// Size of the font.
		/// </summary>
		std::uint32_t FontSize;

		/// <summary>
		/// Padding to apply to the text container.
		/// </summary>
		//Padding Padding;

		/// <summary>
		/// Defines the texts horizontal alignment within the container.
		/// </summary>
		//HorizontalAlignment HorizAlign = HorizontalAlignment::Left;

		/// <summary>
		/// Defines the texts vertical alignment within the container.
		/// </summary>
		//VerticalAlignment VertAlign = VerticalAlignment::Top;
	};

	std::shared_ptr<ITextLabel> BuildTextLabel(const std::string& text, const sf::Vector2f& position, const TextLabelStyle& textLabelStyle);
}