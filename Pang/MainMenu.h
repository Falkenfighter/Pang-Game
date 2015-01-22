#pragma once
#include "stdafx.h"

class MainMenu
{
public:
	enum MenuResult
	{
		Nothing,
		Exit,
		Play
	};

	struct MenuItem
	{
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;
};