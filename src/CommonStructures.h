#pragma once

namespace Menu
{
	/// <summary>
	/// Container to store padding values.
	/// </summary>
	/*struct Padding
	{
		/// <summary>
		/// Padding to apply to the bottom of the container.
		/// Units in pixels.
		/// </summary>
		float Bottom = 0.0f;

		/// <summary>
		/// Padding to apply to the left of the container.
		/// Units in pixels.
		/// </summary>
		float Left = 0.0f;

		/// <summary>
		/// Padding to apply to the right of the container.
		/// Units in pixels.
		/// </summary>
		float Right = 0.0f;

		/// <summary>
		/// Padding to apply to the top of the container.
		/// Units in pixels.
		/// </summary>
		float Top = 0.0f;
	};*/

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
}