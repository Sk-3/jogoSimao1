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
*	Respons�vel por criar vetores de entidades para que suas classes filhas possam instanciar entidades
* 
*	Cria tamb�m um gerenciador de gravidade e um gerenciador de colis�es
*
*	
*/
namespace Fases{
	class GameState : public State
	{

		typedef struct{

		}ArraysDoJogo;
	protected:
		sf::View view;
		Gerenciadores::GerenciadorColisao colision;
		Gravidade gravity;
		Hud hud;
		
		Entidades::Personagens::Player* player2;
		Entidades::Personagens::Player* player;
		
		std::vector<Entidades::Entity*> entidades;
		std::vector<Entidades::Projetil*> projeteis;
		std::vector<Entidades::Obstaculos::Obstaculo*> obstaculos;
		std::vector<Entidades::Personagens::Character*> characters;
	public:
		~GameState();
		GameState();
		virtual void handleEvent();
		virtual void executar() = 0;
		virtual void executarJanela();
		void removerProjeteis();
		void removerPersonagens();
		virtual void criarInimigos() = 0;
		virtual void criarEstruturas() = 0;
	};
}