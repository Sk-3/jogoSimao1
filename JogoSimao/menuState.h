#pragma once
#include "State.h"
#include "Button.h"
#include <vector>
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

