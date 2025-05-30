#pragma once
#include <SFML/Graphics.hpp>
#include "Actions.h"
#include "Ente.h"
#include <vector>
#include "PauseState.h"
#include "Fase2.h"
#include "Fase1.h"
#include "GameOver.h"
#include "MenuPrincipal.h"
#include "MenuSelectLvl.h"
/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe concreta Gerenciador de estados
*	Responsável por:
*		criar uma pilha de estados e executar o topo da pilha
*		Ler mudanças na ação do estado do topo da pilha
*		caso ocorra alguma no atributo "action", realiza alguma ação como por exemplo:
*			abrir menu
*			voltar menu
*			iniciar jogo1
*			etc...
*/


namespace Gerenciadores{
	class GerenciadorEstado : public Ente
	{
	private:
		static GerenciadorEstado* pGerEstado;
		sf::RenderWindow* window;
		std::vector<State*> stack;
	public:
		static GerenciadorEstado* getGerEstado();
		GerenciadorEstado();
		void handleEvent();
		void update();
		void draw();
		void executar();
		void pop();
		void push(State* newState);
		void clear();

	};

}