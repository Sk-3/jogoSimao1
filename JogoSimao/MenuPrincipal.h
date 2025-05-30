#pragma once
#include "menuState.h"
/**
*	Felipe Simbalista: 25/05/2025 
*
*	Classe concreta menuPrincipal
* 
*	Instancia botões para começar o jogo, sair do jogo e para ver o ranking atual
*/

class MenuPrincipal : public menuState
{
private:
	Entidades::Button* start;
	Entidades::Button* quit;
	Entidades::Button* ranking;
public:
	MenuPrincipal();
	~MenuPrincipal();
};

