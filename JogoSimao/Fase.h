#pragma once

#include <cstdlib>
#include "State.h"
#include "Jogador.h"
#include "Estrutura.h"
#include "Plataforma.h"
#include "Cachorro.h"
#include "Fosso.h"
#include "Espinho.h"
#include "Esqueleto.h"
#include "Projetil.h"
#include "GerenciadorColisao.h"
#include "Hud.h"
#include <sstream>
#include <fstream>
#include "ListaEntidades.h"
#include "Atirador.h"



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
	class Fase : public State
	{
	protected:
		int pontuacaoTotal;
		int id;
		//CONTROLADOR DE JANELA		
		sf::View view;
		Hud hud;
		//GERENCIADORES
		Gerenciadores::GerenciadorColisao gerenciadorColisao;
		//LISTA ENTIDADES
		Listas::ListaEntidades listaEntidades;

		bool player2Ativo;
		//PLAYERS
		Entidades::Personagens::Jogador* player2;
		Entidades::Personagens::Jogador* player;	
	public:
		~Fase();
		Fase(Entidades::Personagens::Jogador* jg1, Entidades::Personagens::Jogador* jg2, bool carregaArquivo);
		virtual void handleEvent();
		virtual void executar() = 0;
		virtual void executarJanela();
		void salvar();
				
		//CRIAR ENTIDADES
		int getPontuacaoTotal(); 
		void carregarSalvamento();
		virtual void carregamentoPadrao();

		void criarCachorro(Entidades::Personagens::Atirador* dono);
		void criarCachorro();
		void criarPlataformas();
		virtual void criarInimigos() = 0;
		virtual void criarObstaculo() = 0;
		void controladorEstado(int id);
		void criarCenario();
		void aplicarGravidade();
		int verificarQuantidadeInimigos();
	};
}