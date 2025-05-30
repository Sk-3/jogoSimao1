#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal()
	:menuState()
{
	start = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 300.f), "Start Game", Actions::SELECIONAR_FASE);

	quit = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 400.f), "Quit Game", Actions::VOLTAR_1_MENU);

	ranking = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 500.f), "Ranking", Actions::VOLTAR_1_MENU);
	buttonVector.push_back(start);
	buttonVector.push_back(quit);
	buttonVector.push_back(ranking);
}

MenuPrincipal::~MenuPrincipal()
{
	delete start;
	delete quit;
	delete ranking;
}

