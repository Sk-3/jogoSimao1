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
public:
	PauseState(Fases::Fase* pFase);
	~PauseState();
	void readButtons() override;
	void carregarBotoes();
};

