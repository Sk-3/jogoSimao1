#include "GameOver.h"

GameOver::GameOver()
{
	voltar = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 300.f), "Voltar", Actions::VOLTAR_2_MENUS);
	buttonVector.push_back(voltar);
}

GameOver::~GameOver()
{
	delete voltar;
}
