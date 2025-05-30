#pragma once
#include "State.h"
#include "Player.h"
#include "Gravidade.h"
#include "Plataforma.h"
#include "Projetil.h"
#include "GerenciadorColisao.h"
#include "Hud.h"
#include <sstream>

/**
*	Felipe Simbalista: 25/05/2025
* 
*	Classe abstrata GameState
*	Responsável por criar vetores de entidades para que suas classes filhas possam instanciar entidades
* 
*	Cria também um gerenciador de gravidade e um gerenciador de colisões
*
*	
*/
namespace Fases{
	class GameState : public State
	{
	protected:
		sf::View view;
		Gerenciadores::GerenciadorColisao colision;
		Gravidade gravity;
		Hud hud;
		
		Entidades::Player* player2;
		Entidades::Player* player;
		
		std::vector<Entidades::Entity*> entidades;
		std::vector<Entidades::Projetil*> projeteis;
		std::vector<Entidades::Obstaculo*> obstaculos;
		std::vector<Entidades::Character*> characters;
	public:
		~GameState();
		GameState();
		virtual void handleEvent();
		void dispararProjetil(Entidades::Character* character);
		virtual void executar() = 0;
		void removerProjeteis();
		void removerPersonagens();
	};
}