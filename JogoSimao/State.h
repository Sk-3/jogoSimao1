#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "Actions.h"
#include "mediadorEventos.h"
/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe abstrata State
* 
*	Gera uma view para cada estado e aplica na window
* 
*	Cada estado tem uma ação que vai ser lida pelo gerenciador de estados
* 
*	é responsável pelo mouse position da sua própria view
*/

class State : public Ente
{
protected:
	sf::View* view;
	mediadorEventos* mediador;
	sf::Vector2i* mousePos;
public:
	State();
	virtual ~State();
	virtual void handleEvent() = 0;
	virtual void executar() = 0;

};

