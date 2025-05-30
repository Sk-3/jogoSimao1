#pragma once
#include "State.h"
#include "Button.h"
#include <vector>
/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe abstrata menuState
*
*	cria um vetor de bot�es para suas classes filhas instanciar bot�es nele
* 
*	Classe respons�vel por ler as a��es dos bot�es e mudar a a��o do estado caso o bot�o seja clicado
*/
class menuState : public State
{
protected:
	std::vector<Entidades::Button*> buttonVector;
	
public:
	virtual ~menuState();
	menuState();


	void readButtons();
	void execButtons();
	virtual void handleEvent();
	virtual void executar();
	virtual void mouseClick();

};

