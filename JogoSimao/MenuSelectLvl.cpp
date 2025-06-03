#include "MenuSelectLvl.h"

MenuSelectLvl::MenuSelectLvl()
	:menuState()
{
	/**
	* @brief Cria os bot�es do menu de sele��o de n�veis.
	* @details Cria dois bot�es para selecionar os n�veis 1 e 2 do jogo e os adiciona ao vetor de bot�es.
	*/


	voltar = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(50.f, 100.f), "Voltar", Actions::VOLTAR_1_MENU);
	level1 = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 300.f), "Level 1", Actions::FASE_1);
	level2 = new Entidades::Button(sf::Vector2f(200.f, 100.f), sf::Vector2f(200.f, 400.f), "Level 2", Actions::FASE_2);

	buttonVector.push_back(voltar);
	buttonVector.push_back(level1);
	buttonVector.push_back(level2);
}

MenuSelectLvl::~MenuSelectLvl()
{
	/**
	*@brief Destrutor da classe MenuSelectLvl.
	*@details Libera a mem�ria alocada para os bot�es de sele��o de n�veis.
	*/
	delete level1;
	delete level2;
}

