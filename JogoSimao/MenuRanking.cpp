#include "MenuRanking.h"

MenuRanking::MenuRanking()
:menuState()
{
	voltar = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(50.f, 100.f), "Voltar", Actions::VOLTAR_1_MENU);
	buttonVector.push_back(voltar);
}

MenuRanking::~MenuRanking()
{
}
