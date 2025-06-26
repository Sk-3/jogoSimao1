#include "State.h"
State::State()
:Ente()
{
	/**
	*@brief Construtor da classe State, inicializa os atributos
	*/
	mediador = mediadorEventos::getMediadorEventos();
	mousePos = pGerGraphic->getMousePosition();
	view = new sf::View(sf::FloatRect(0,0,1280,720));
	pGerGraphic->setView(*view);
}

State::~State() {
	delete view;
}