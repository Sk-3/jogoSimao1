#pragma once
#include "menuState.h"

/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe concreta menuPrincipal
*
*	Instancia botões para selecionar o nivel que deseja jogar
*/
class MenuSelectLvl : public menuState
{
private:
	Entidades::Button* voltar;
	Entidades::Button* level1;
	Entidades::Button* level2;
public:
	MenuSelectLvl();
	~MenuSelectLvl();
};

