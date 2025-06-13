#include "Fase1.h"

namespace Fases{
	Fase1::Fase1() :
		GameState()
	{
		//Criação das plataformas da fase
		
		criarEstruturas();
		criarInimigos();
		
	}

	Fase1::~Fase1()
	{
	}

	void Fase1::executar()
	{
		/**
		*@brief funcao principal da fase
		*@details Centraliza a camera no jogador e logo após gerencia os eventos de input e executa as entidades
		*	caso alguma entidade colida com a outra, o gerenciador de colisoes trata isso, e após o tratamento
		*	as entidades são desenhadas na tela
		*	no final remove os personagens e projeteis da tela
		*	caso o player morra, aciona tela de game over
		*/
		

		executarJanela();
		handleEvent();
		for (auto const& obst : obstaculos) {
			obst->executar();
		}
		for (auto const& charact : characters) {
			charact->executar();
		}
		for (auto const& projetil : projeteis) {
			projetil->executar();
		}
		gravity.executar();
		colision.executar();
		
		hud.executar();

		for (auto const& charact : characters) {
			charact->desenhar();
		}
		for (auto const& projetil : projeteis) {
			projetil->desenhar();
		}
		for (auto const& obst : obstaculos) {
			obst->desenhar();
		}

		for (auto const& estrut : estruturas) {
			estrut->desenhar();
		}
		
		hud.draw();
		removerProjeteis();
		if (!player->vivo())
		{
			setAction(Actions::GAME_OVER);
		}
		removerPersonagens();

		
	}

	void Fase1::criarInimigos()
	{
		/***
		* @brief Inicizaliza os inimigos da fase no construtor
		* @details Cria os inimigos e adiciona na lista de personagens e ded entidades
		* @return void
		*/

		criarAtirador();

		Entidades::Personagens::Boss* boss = new Entidades::Personagens::Boss(sf::Vector2f(100, 200), sf::Vector2f(2500, 300), player, &projeteis);
		characters.emplace_back(boss);
		listaEntidades.inserirNoFim(boss);
	}

	void Fase1::criarAtirador()
	{
		Entidades::Personagens::Atirador* atirador = new Entidades::Personagens::Atirador(sf::Vector2f(60, 100), sf::Vector2f(1500, 300), player, &projeteis, &characters);
		characters.emplace_back(atirador);
		listaEntidades.inserirNoFim(atirador);
	}

	void Fase1::criarCachorro()
	{
	}

	void Fase1::criarEstruturas()
	{
		/***
		* @brief Inicizaliza as estruturas da fase no construtor
		* @details Cria as estruturas e adiciona na lista de obstaculos
		* @return void
		*/

		for (int i = 0; i <= 100; i++) {
			Entidades::Obstaculos::Espinhos* esp = new Entidades::Obstaculos::Espinhos(sf::Vector2f(100.f, 100.f), sf::Vector2f(100 * i, 500));
			listaEntidades.inserirNoFim(esp);
			obstaculos.push_back(esp);

			Entidades::Estrutura* estrutura = new Entidades::Estrutura(sf::Vector2f(100.f, 100.f), sf::Vector2f(100 * i, 670),TipoEstrutura::CHAO);
			listaEntidades.inserirNoFim(estrutura);
			estruturas.push_back(estrutura);			
		}				
	}


}