#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "Actions.h"
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
	sf::RenderWindow* window;
	Actions action2;
	sf::Font* font;
	sf::Vector2i* mousePos;
public:
	State();
	virtual ~State();
	const Actions getAction() const;
	void setAction(Actions action);
	
	virtual void handleEvent() = 0;
	virtual void executar() = 0;

};

