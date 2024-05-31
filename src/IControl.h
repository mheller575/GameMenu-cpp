
#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>

namespace Menu
{
	/// <summary>
	/// Interface for a Control object.
	/// </summary>
	class IControl
	{
	public:
		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~IControl();

		/// <summary>
		/// Draws the object on the provided render target.
		/// </summary>
		/// <param name="window">Target to draw on.</param>
		virtual void Draw(sf::RenderTarget* window) = 0;

		/// <summary>
		/// Handles a window event applied to the object.
		/// </summary>
		/// <param name="event">Received event.</param>
		/// <param name="window">Render target to be passed along for actions tied to object items.</param>
		virtual void HandleEvent(const sf::Event& event, sf::RenderTarget* window) = 0;
	};
}
