#pragma once
#include "State.h"
#include "Player.h"
#include "Gravidade.h"
#include "Plataforma.h"
#include "Projetil.h"
#include "GerenciadorColisao.h"
#include "Hud.h"
#include <sstream>
#include "ListaEntidades.h"

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

		Listas::ListaEntidades listaEntidades;
		
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