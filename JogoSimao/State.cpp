#include "State.h"
State::State()
:Ente()
{
	/**
	*@brief Construtor da classe State, inicializa os atributos
	*/
	action2 = Actions::NADA;
	mousePos = pGerGraphic->getMousePosition();
	view = new sf::View(sf::FloatRect(0,0,1280,720));
	window = pGerGraphic->getWindow();
	pGerGraphic->setView(*view);
}

State::~State() {
	delete view;
}

const Actions State::getAction() const{
	/**
	*@brief Retorna a a��o atual do estado
	*@return Actions - Acao atual do estado
	*/
	return action2;
}

void State::setAction(Actions action)
{
	/**
	*@brief Define a acao atual do estado
	*@param Action - Acao a ser definida
	*@return void
	*/
	this->action2 = action;
}
