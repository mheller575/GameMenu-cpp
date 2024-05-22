
#pragma once

#include <string>

#include <SFML/Graphics.hpp>

namespace Menu
{
	std::string ConvertEventDataToString(const sf::Event& eventObj);

	std::string ConvertEventTypeToString(const sf::Event::EventType& eventType);

	std::string ConvertKeyToString(const sf::Keyboard::Key& eventObj);

	std::string ConvertWheelToString(const sf::Mouse::Wheel& wheel);

	std::string ConvertMouseButtonToString(const sf::Mouse::Button& button);

	std::string ConvertJoystickAxisToString(const sf::Joystick::Axis& axis);
}