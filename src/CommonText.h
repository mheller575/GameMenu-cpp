
#pragma once

#include <SFML/Graphics.hpp>

#include "CommonStructures.h"

namespace Menu
{
	/// <summary>
	/// Defines horizontal alignment options to be applied to containers.
	/// </summary>
	enum class HorizontalAlignment
	{
		/// <summary>
		/// Aligns containers to the left of the window.
		/// </summary>
		Left = 0,
		/// <summary>
		/// Aligns containers to the center of the window.
		/// </summary>
		Center = 1,
		/// <summary>
		/// Aligns containers to the right of the window.
		/// </summary>
		Right = 2,
	};

	/// <summary>
	/// Defines vertical alignment options to be applied to containers.
	/// </summary>
	enum class VerticalAlignment
	{
		/// <summary>
		/// Aligns containers to the top of the window.
		/// </summary>
		Top = 0,
		/// <summary>
		/// Aligns containers to the center of the window.
		/// </summary>
		Center = 1,
		/// <summary>
		/// Aligns containers to the bottom of the window.
		/// </summary>
		Bottom = 2,
	};

	/// <summary>
	/// Defines the style for a text box.
	/// </summary>
	struct TextStyle
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
		Padding Padding;

		/// <summary>
		/// Defines the texts horizontal alignment within the container.
		/// </summary>
		HorizontalAlignment HorizAlign = HorizontalAlignment::Left;

		/// <summary>
		/// Defines the texts vertical alignment within the container.
		/// </summary>
		VerticalAlignment VertAlign = VerticalAlignment::Top;
	};

	/// <summary>
	/// Gets the texts position within the container accounting for the texts alignment.
	/// </summary>
	/// <param name="containerSize">Dimensions of the container the text will reside in</param>
	/// <param name="textSize">Dimensions of the text.</param>
	/// <param name="textPadding">Padding to apply to the text object.</param>
	/// <param name="horizontal">Alignment of the text in the horizontal direction.</param>
	/// <param name="vertical">Alignment of the text in the vertical direction.</param>
	/// <returns>Expected position of the text.</returns>
	sf::Vector2f GetTextPosition(const sf::FloatRect& containerSize, const sf::FloatRect& textSize, const Padding& textPadding,
		const HorizontalAlignment& horizontal, const VerticalAlignment& vertical, const sf::Vector2f& overallPosition);
}