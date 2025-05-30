#pragma once
#include "menuState.h"
/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe concreta PauseState
*
*	Instancia botões para voltar pro jogo e para sair do jogo
* 
*/

class PauseState : public menuState
{
private:
	sf::RectangleShape box;
	Entidades::Button* resume;
	Entidades::Button* quit;

public:
	PauseState();
	~PauseState();
};

