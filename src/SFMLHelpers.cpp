
#include <sstream>
#include <unordered_map>

#include "SFMLHelpers.h"

namespace Menu
{
	static std::unordered_map<sf::Event::EventType, std::string> EventTypeToString =
	{
		{ sf::Event::EventType::Closed, "Closed" },
		{ sf::Event::EventType::Resized, "Resized" },
		{ sf::Event::EventType::LostFocus, "LostFocus" },
		{ sf::Event::EventType::GainedFocus, "GainedFocus" },
		{ sf::Event::EventType::TextEntered, "TextEntered" },
		{ sf::Event::EventType::KeyPressed, "KeyPressed" },
		{ sf::Event::EventType::KeyReleased, "KeyReleased" },
		{ sf::Event::EventType::MouseWheelMoved, "MouseWheelMoved" },
		{ sf::Event::EventType::MouseWheelScrolled, "MouseWheelScrolled" },
		{ sf::Event::EventType::MouseButtonPressed, "MouseButtonPressed" },
		{ sf::Event::EventType::MouseButtonReleased, "MouseButtonReleased" },
		{ sf::Event::EventType::MouseMoved, "MouseMoved" },
		{ sf::Event::EventType::MouseEntered, "MouseEntered" },
		{ sf::Event::EventType::MouseLeft, "MouseLeft" },
		{ sf::Event::EventType::JoystickButtonPressed, "JoystickButtonPressed" },
		{ sf::Event::EventType::JoystickButtonReleased, "JoystickButtonReleased" },
		{ sf::Event::EventType::JoystickMoved, "JoystickMoved" },
		{ sf::Event::EventType::JoystickConnected, "JoystickConnected" },
		{ sf::Event::EventType::JoystickDisconnected, "JoystickDisconnected" },
		{ sf::Event::EventType::TouchBegan, "TouchBegan" },
		{ sf::Event::EventType::TouchMoved, "TouchMoved" },
		{ sf::Event::EventType::TouchEnded, "TouchEnded" },
		{ sf::Event::EventType::SensorChanged, "SensorChanged" },
	};

	static std::unordered_map<sf::Keyboard::Key, std::string> KeyToString = 
	{
		{ sf::Keyboard::Key::A, "A" },
		{ sf::Keyboard::Key::B, "B" },
		{ sf::Keyboard::Key::C, "C" },
		{ sf::Keyboard::Key::D, "D" },
		{ sf::Keyboard::Key::E, "E" },
		{ sf::Keyboard::Key::F, "F" },
		{ sf::Keyboard::Key::G, "G" },
		{ sf::Keyboard::Key::H, "H" },
		{ sf::Keyboard::Key::I, "I" },
		{ sf::Keyboard::Key::J, "J" },
		{ sf::Keyboard::Key::K, "K" },
		{ sf::Keyboard::Key::L, "L" },
		{ sf::Keyboard::Key::M, "M" },
		{ sf::Keyboard::Key::N, "N" },
		{ sf::Keyboard::Key::O, "O" },
		{ sf::Keyboard::Key::P, "P" },
		{ sf::Keyboard::Key::Q, "Q" },
		{ sf::Keyboard::Key::R, "R" },
		{ sf::Keyboard::Key::S, "S" },
		{ sf::Keyboard::Key::T, "T" },
		{ sf::Keyboard::Key::U, "U" },
		{ sf::Keyboard::Key::V, "V" },
		{ sf::Keyboard::Key::W, "W" },
		{ sf::Keyboard::Key::X, "X" },
		{ sf::Keyboard::Key::Y, "Y" },
		{ sf::Keyboard::Key::Z, "Z" },
		{ sf::Keyboard::Key::Num0, "Num0" },
		{ sf::Keyboard::Key::Num1, "Num1" },
		{ sf::Keyboard::Key::Num2, "Num2" },
		{ sf::Keyboard::Key::Num3, "Num3" },
		{ sf::Keyboard::Key::Num4, "Num4" },
		{ sf::Keyboard::Key::Num5, "Num5" },
		{ sf::Keyboard::Key::Num6, "Num6" },
		{ sf::Keyboard::Key::Num7, "Num7" },
		{ sf::Keyboard::Key::Num8, "Num8" },
		{ sf::Keyboard::Key::Num9, "Num9" },
		{ sf::Keyboard::Key::Escape, "Escape" },
		{ sf::Keyboard::Key::LControl, "LControl" },
		{ sf::Keyboard::Key::LShift, "LShift" },
		{ sf::Keyboard::Key::LAlt, "LAlt" },
		{ sf::Keyboard::Key::LSystem, "LSystem" },
		{ sf::Keyboard::Key::RControl, "RControl" },
		{ sf::Keyboard::Key::RShift, "RShift" },
		{ sf::Keyboard::Key::RAlt, "RAlt" },
		{ sf::Keyboard::Key::RSystem, "RSystem" },
		{ sf::Keyboard::Key::Menu, "Menu" },
		{ sf::Keyboard::Key::LBracket, "LBracket" },
		{ sf::Keyboard::Key::RBracket, "RBracket" },
		{ sf::Keyboard::Key::Semicolon, "Semicolon" },
		{ sf::Keyboard::Key::Comma, "Comma" },
		{ sf::Keyboard::Key::Period, "Period" },
		{ sf::Keyboard::Key::Apostrophe, "Apostrophe" },
		{ sf::Keyboard::Key::Slash, "Slash" },
		{ sf::Keyboard::Key::BackSlash, "BackSlash" },
		{ sf::Keyboard::Key::Grave, "Grave" },
		{ sf::Keyboard::Key::Equal, "Equal" },
		{ sf::Keyboard::Key::Hyphen, "Hyphen" },
		{ sf::Keyboard::Key::Space, "Space" },
		{ sf::Keyboard::Key::Enter, "Enter" },
		{ sf::Keyboard::Key::Backspace, "Backspace" },
		{ sf::Keyboard::Key::Tab, "Tab" },
		{ sf::Keyboard::Key::PageUp, "PageUp" },
		{ sf::Keyboard::Key::PageDown, "PageDown" },
		{ sf::Keyboard::Key::End, "End" },
		{ sf::Keyboard::Key::Home, "Home" },
		{ sf::Keyboard::Key::Insert, "Insert" },
		{ sf::Keyboard::Key::Delete, "Delete" },
		{ sf::Keyboard::Key::Add, "Add" },
		{ sf::Keyboard::Key::Subtract, "Subtract" },
		{ sf::Keyboard::Key::Multiply, "Multiply" },
		{ sf::Keyboard::Key::Divide, "Divide" },
		{ sf::Keyboard::Key::Left, "Left" },
		{ sf::Keyboard::Key::Right, "Right" },
		{ sf::Keyboard::Key::Up, "Up" },
		{ sf::Keyboard::Key::Down, "Down" },
		{ sf::Keyboard::Key::Numpad0, "Numpad0" },
		{ sf::Keyboard::Key::Numpad1, "Numpad1" },
		{ sf::Keyboard::Key::Numpad2, "Numpad2" },
		{ sf::Keyboard::Key::Numpad3, "Numpad3" },
		{ sf::Keyboard::Key::Numpad4, "Numpad4" },
		{ sf::Keyboard::Key::Numpad5, "Numpad5" },
		{ sf::Keyboard::Key::Numpad6, "Numpad6" },
		{ sf::Keyboard::Key::Numpad7, "Numpad7" },
		{ sf::Keyboard::Key::Numpad8, "Numpad8" },
		{ sf::Keyboard::Key::Numpad9, "Numpad9" },
		{ sf::Keyboard::Key::F1, "F1" },
		{ sf::Keyboard::Key::F2, "F2" },
		{ sf::Keyboard::Key::F3, "F3" },
		{ sf::Keyboard::Key::F4, "F4" },
		{ sf::Keyboard::Key::F5, "F5" },
		{ sf::Keyboard::Key::F6, "F6" },
		{ sf::Keyboard::Key::F7, "F7" },
		{ sf::Keyboard::Key::F8, "F8" },
		{ sf::Keyboard::Key::F9, "F9" },
		{ sf::Keyboard::Key::F10, "F10" },
		{ sf::Keyboard::Key::F11, "F11" },
		{ sf::Keyboard::Key::F12, "F12" },
		{ sf::Keyboard::Key::F13, "F13" },
		{ sf::Keyboard::Key::F14, "F14" },
		{ sf::Keyboard::Key::F15, "F15" },
		{ sf::Keyboard::Key::Pause, "Pause" },
	};

	static std::unordered_map<sf::Mouse::Wheel, std::string> WheelToString =
	{
		{ sf::Mouse::Wheel::HorizontalWheel, "HorizontalWheel" },
		{ sf::Mouse::Wheel::VerticalWheel, "VerticalWheel" },
	};

	static std::unordered_map<sf::Mouse::Button, std::string> ButtonToString =
	{
		{ sf::Mouse::Button::Left, "Left" },
		{ sf::Mouse::Button::Middle, "Middle" },
		{ sf::Mouse::Button::Right, "Right" },
		{ sf::Mouse::Button::XButton1, "XButton1" },
		{ sf::Mouse::Button::XButton2, "XButton2" },
	};

	static std::unordered_map<sf::Joystick::Axis, std::string> JoystickAxisToString =
	{
		{ sf::Joystick::Axis::X, "X" },
		{ sf::Joystick::Axis::Y, "Y" },
		{ sf::Joystick::Axis::Z, "Z" },
		{ sf::Joystick::Axis::R, "R" },
		{ sf::Joystick::Axis::U, "U" },
		{ sf::Joystick::Axis::V, "V" },
		{ sf::Joystick::Axis::PovX, "PovX" },
		{ sf::Joystick::Axis::PovY, "PovY" },
	};

	std::string ConvertEventDataToString(const sf::Event& eventObj)
	{
		switch (eventObj.type)
		{
		case sf::Event::EventType::Resized:
			return "Height:" + std::to_string(eventObj.size.height) + 
				" Width:" + std::to_string(eventObj.size.width);
		case sf::Event::EventType::TextEntered:
			return "Unicode:" + eventObj.text.unicode;
		case sf::Event::EventType::KeyPressed:
		case sf::Event::EventType::KeyReleased:
		{
			std::stringstream strStream;
			if (eventObj.key.alt)
			{
				strStream << "Alt+";
			}

			if (eventObj.key.control)
			{
				strStream << "Ctrl+";
			}

			if (eventObj.key.shift)
			{
				strStream << "Shift+";
			}

			if (eventObj.key.system)
			{
				// TODO: Add an OS specific string here.
				strStream << "System+";
			}

			strStream << ConvertKeyToString(eventObj.key.code);

			return strStream.str();
		}
		case sf::Event::EventType::MouseWheelScrolled:
			return "X:" + std::to_string(eventObj.mouseWheelScroll.x) + " Y:"
				+ std::to_string(eventObj.mouseWheelScroll.y) + " Wheel:"
				+ ConvertWheelToString(eventObj.mouseWheelScroll.wheel)
				+ " Delta:" + std::to_string(eventObj.mouseWheelScroll.delta);
		case sf::Event::EventType::MouseButtonPressed:
		case sf::Event::EventType::MouseButtonReleased:
			return "X:" + std::to_string(eventObj.mouseButton.x) + " Y:"
				+ std::to_string(eventObj.mouseButton.y) + " Button:"
				+ ConvertMouseButtonToString(eventObj.mouseButton.button);
		case sf::Event::EventType::MouseMoved:
			return "X:" + std::to_string(eventObj.mouseMove.x) + " Y:"
				+ std::to_string(eventObj.mouseMove.y);
		case sf::Event::EventType::JoystickButtonPressed:
		case sf::Event::EventType::JoystickButtonReleased:
			return "JoystickID:" + std::to_string(eventObj.joystickButton.joystickId)
				+ " Button:" + std::to_string(eventObj.joystickButton.button);
		case sf::Event::EventType::JoystickMoved:
			return "JoystickID:" + std::to_string(eventObj.joystickMove.joystickId)
				+ " Position:" + std::to_string(eventObj.joystickMove.position)
				+ " Axis:" + std::to_string(eventObj.joystickMove.axis);
		case sf::Event::EventType::JoystickConnected:
		case sf::Event::EventType::JoystickDisconnected:
			return "JoystickID:" + std::to_string(eventObj.joystickConnect.joystickId);
		case sf::Event::EventType::TouchBegan:
		case sf::Event::EventType::TouchMoved:
		case sf::Event::EventType::TouchEnded:
			return "Finger:" + std::to_string(eventObj.touch.finger)
				+ " X:" + std::to_string(eventObj.touch.x)
				+ " Y:" + std::to_string(eventObj.touch.y);
		default:
			return "";
		}
	}

	std::string ConvertEventTypeToString(const sf::Event::EventType& eventType)
	{
		return EventTypeToString.find(eventType) != EventTypeToString.end()
			? EventTypeToString.at(eventType)
			: "UNKNOWN";
	}

	std::string ConvertKeyToString(const sf::Keyboard::Key& key)
	{
		return KeyToString.find(key) != KeyToString.end()
			? KeyToString.at(key)
			: "UNKNOWN";
	}

	std::string ConvertWheelToString(const sf::Mouse::Wheel& wheel)
	{
		return WheelToString.find(wheel) != WheelToString.end()
			? WheelToString.at(wheel)
			: "UNKNOWN";
	}

	std::string ConvertMouseButtonToString(const sf::Mouse::Button& button)
	{
		return ButtonToString.find(button) != ButtonToString.end()
			? ButtonToString.at(button)
			: "UNKNOWN";
	}

	std::string ConvertJoystickAxisToString(const sf::Joystick::Axis& axis)
	{
		return JoystickAxisToString.find(axis) != JoystickAxisToString.end()
			? JoystickAxisToString.at(axis)
			: "UNKNOWN";
	}
}