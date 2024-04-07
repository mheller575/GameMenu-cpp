#include <iostream>
#include <string>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>

#include "game_menu_impl.h"

game_menu::MENU* create_menu_context(sf::RenderWindow& wnd, game_menu::MenuConfig& config)
{
	return reinterpret_cast<game_menu::MENU*>(new game_menu::Menu(wnd, config));
}

void menu_destroy_context(game_menu::MENU* menu) 
{
	delete reinterpret_cast<game_menu::Menu*>(menu);
}

void menu_handle_event(game_menu::MENU* menu, sf::Event& event)
{
	reinterpret_cast<game_menu::Menu*>(menu)->HandleEvent(event);
}

void menu_render(game_menu::MENU* menu)
{
	reinterpret_cast<game_menu::Menu*>(menu)->Render();
}

namespace game_menu 
{
	float GetOffsetCoefficient(const Align& alignment);

	Menu::Menu(sf::RenderTarget& window, const MenuConfig& config)
		: _window(window)
		, _style(config.style)
		, _title(config.title)
	{
		for (auto& menu_item : config.items)
		{
			_items.push_back({ menu_item, {0, 0} });
			std::cout << " Processing item " << menu_item.name << std::endl;
		}

		std::cout << "Size of items : " << _items.size() << std::endl;
	}

	void Menu::HandleEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed) 
		{
			const auto itemCount = _items.size();
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				_currentlySelectedItem = (_currentlySelectedItem + itemCount - 1) % itemCount;
				break;
			case sf::Keyboard::Down:
				_currentlySelectedItem = (_currentlySelectedItem + 1) % itemCount;
				break;
			case sf::Keyboard::Return:
				_items[_currentlySelectedItem].Data.action(_window);
				break;
			}
		}
	}

	void Menu::Render()
	{
		SetMenu();
		DrawMenu();
	}

	void Menu::WriteText(const std::string& str, const sf::Font& font, const float& size, const float& x, const float& y, const sf::Color& color)
	{
		sf::Text text;
		text.setString(str);
		text.setFont(font);
		text.setFillColor(color);
		text.setCharacterSize(size);
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.width / 2.0f, 0);

		auto textX = x;
		if (textX - textRect.width / 2.0f < 0)
		{
			textX = textRect.width / 2 + _style.PaddingTitle.left;
		}

		if (textX + textRect.width / 2.0f > _window.getSize().x)
		{
			textX = _window.getSize().x - textRect.width / 2 + _style.PaddingTitle.left;
		}

		text.setPosition(sf::Vector2f(textX, y));
		_window.draw(text);
	}

	void Menu::SetMenu()
	{
		/* Setting title of menu */
		const auto titleOffsetCoefficient = GetOffsetCoefficient(_style.TitleAlign);

		const auto titleLocationX = ((float)_window.getSize().x * titleOffsetCoefficient) + _style.PaddingTitle.left;
		_titleLocation = sf::Vector2f(titleLocationX, _style.PaddingTitle.top);

		const auto menuScreenHeight = _titleLocation.y + _style.PaddingItems.top;
		const auto blockHeight = (float)_style.ItemFontSize * _style.MenuItemScaleFactor;
		const auto offsetCoefficient = GetOffsetCoefficient(_style.ItemAlign);

		const auto x = (float)_window.getSize().x * offsetCoefficient + _style.PaddingItems.left;
		auto y = menuScreenHeight + blockHeight + _style.PaddingItems.top;

		/* Calculating Menu item locations */
		for (auto i = 0; i < _items.size(); ++i)
		{
			_items[i].Location = sf::Vector2f(x, y);
			y += blockHeight;
		}
	}

	void Menu::DrawMenu() 
	{
		WriteText(_title, _style.ItemFont, _style.TitleFontSize, _titleLocation.x, _titleLocation.y, _style.colorScheme.titleColor);

		for (auto i = 0; i < _items.size(); ++i)
		{
			auto color = i == _currentlySelectedItem ? _style.colorScheme.selectedColor : _style.colorScheme.itemColor;
			WriteText(_items[i].Data.name, _style.ItemFont, _style.ItemFontSize,_items[i].Location.x, _items[i].Location.y, color);
		}
	}

	float GetOffsetCoefficient(const Align& alignment)
	{
		switch (alignment)
		{
		case Align::Left:
			return 0.25f;
		case Align::Right:
			return 0.75f;
		case Align::Center:
		default: // Center is the default alignment if unknown.
			return 0.5f;
		}
	}
}
