#pragma once
#include "State.h"
#include "Jogador.h"
#include "Gravidade.h"
#include "Estrutura.h"
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
*	Respons�vel por criar vetores de entidades para que suas classes filhas possam instanciar entidades
* 
*	Cria tamb�m um gerenciador de gravidade e um gerenciador de colis�es
*
*	
*/
namespace Fases{
	class Fase : public State
	{
	protected:
		//CONTROLADOR DE JANELA
		sf::View view;
		Hud hud;
		//GERENCIADORES
		Gerenciadores::GerenciadorColisao colision;
		Gravidade gravity;
		

		//LISTA ENTIDADES
		Listas::ListaEntidades listaEntidades;


		//PLAYERS
		Entidades::Personagens::Jogador* player2;
		Entidades::Personagens::Jogador* player;
		//VETORES
		std::vector<Entidades::Estrutura*> estruturas;
		std::vector<Entidades::Projetil*> projeteis;
		std::vector<Entidades::Obstaculos::Obstaculo*> obstaculos;
		std::vector<Entidades::Personagens::Personagem*> characters;
	public:
		~Fase();
		Fase();
		virtual void handleEvent();
		virtual void executar() = 0;
		virtual void executarJanela();
		void removerProjeteis();
		void removerPersonagens();
		virtual void criarInimigos() = 0;
		virtual void criarEstruturas() = 0;
	};
}