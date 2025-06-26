#pragma once
#include "State.h"
#include "Button.h"
#include <vector>
/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe abstrata menuState
*
*	cria um vetor de botões para suas classes filhas instanciar botões nele
* 
*	Classe responsável por ler as ações dos botões e mudar a ação do estado caso o botão seja clicado
*/
class menuState : public State
{
protected:
	std::vector<Entidades::Button*> buttonVector;
	sf::Sprite fundoMenu;
public:
	virtual ~menuState();
	menuState();

	virtual void carregarBotoes() = 0; 
	void execButtons();
	virtual void handleEvent();
	virtual void executar();
	virtual void mouseClick();

};

