#include "State.h"
State::State()
:Ente()
{
	/**
	*@brief Construtor da classe State, inicializa os atributos
	*/
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
	/**
	*@brief Retorna a ação atual do estado
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
