#include "MenuSelectLvl.h"

MenuSelectLvl::MenuSelectLvl()
	:menuState()
{

	level1 = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 300.f), "Level 1", Actions::FASE_1);
	level2 = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 400.f), "Level 2", Actions::FASE_2);

	buttonVector.push_back(level1);
	buttonVector.push_back(level2);
}

MenuSelectLvl::~MenuSelectLvl()
{
	delete level1;
	delete level2;
}

