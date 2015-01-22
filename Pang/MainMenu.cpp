#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	// Load menu image from file
	sf::Texture texture;
	texture.loadFromFile("images/mainmenu.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);

	/// 
	/// Setup clickable regions
	///

	// Play menu item
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.rect.height = 235;
	playButton.action = Play;

	// Exit menu item
	MenuItem exitButton;
	exitButton.rect.top = 383;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.height = 177;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.top < y && 
			menuItemRect.left < x && 
			(menuItemRect.height + menuItemRect.top) > y && 
			(menuItemRect.width + menuItemRect.left) > x)
		{
			return (*it).action;
		}
	}

	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (true)
	{
		
	}
}
