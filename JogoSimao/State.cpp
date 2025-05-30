#include "State.h"
State::State()
:Ente()
{
	action2 = Actions::NADA;
	window = pGerGraphic->getWindow();
	font = pGerGraphic->getFont();
	mousePos = pGerGraphic->getMousePosition();
	view = new sf::View(sf::FloatRect(0,0,1280,720));
	window->setView(*view);
}

State::~State() {
	
}

const Actions State::getAction() const{
	return action2;
}

void State::setAction(Actions action)
{
	this->action2 = action;
}
