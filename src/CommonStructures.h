#pragma once

namespace Menu
{
	/// <summary>
	/// Container to store padding values.
	/// </summary>
	struct Padding
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
	};
}
