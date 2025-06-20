#pragma once
#include "menuState.h"
#include "Fase.h"
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
	Fases::Fase* fase;
	sf::RectangleShape box;
	Entidades::Button* resume;
	Entidades::Button* salvar;
	Entidades::Button* quit;

public:
	PauseState(Fases::Fase* pFase);
	~PauseState();
	void readButtons() override;
};

