#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.h"
#include <iostream>
#include <cstdlib>
#include "Actions.h"

/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe respons�vel por criar bot�es e gerenciar suas a��es
*	Classe agregada aos menus
*	seu atributo buttonAction � respons�vel por dizer qual a��o ele vai tomar quando clicado
*	seu atributo actualAction vai ser lido pelo menuState, quando ele for clicado ele vai mudar de "NADA" para a a��o de buttonAction
*/
namespace Entidades{
	class Button : public Entity
	{
	private:


		sf::Text buttonText;
		Actions buttonAction;
		Actions actualAction;


	
	public:
		Button(sf::Vector2f size, sf::Vector2f pos,std::string txt = "", Actions action = Actions::NADA);
		~Button();


		void setAction(Actions act);
		virtual bool getClicked(sf::Vector2i* mousePos);
		const Actions getAction();
		void action();
		void executar();
	};

}