#include "Fase1.h"

namespace Fases{
	Fase1::Fase1() :
		GameState()
	{
		//Criação das plataformas da fase
		
		projeteis.reserve(100);
		characters.reserve(20);
		obstaculos.reserve(100);
		criarEstruturas();
		criarInimigos();
		
	}

	Fase1::~Fase1()
	{
	}

	void Fase1::executar()
	{
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
		colision.executar();
		gravity.executar();
		hud.executar();



		for (auto const& charact : characters) {
			charact->draw();
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
		* @details Cria os inimigos e adiciona na lista de personagens
		* @return void
		*/
		characters.emplace_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 50), sf::Vector2f(900, 300)));
		characters.emplace_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 50), sf::Vector2f(700, 300)));
		characters.emplace_back(new Entidades::Personagens::Boss(sf::Vector2f(100, 200), sf::Vector2f(1500, 300), player, &projeteis));
	}

	void Fase1::criarEstruturas()
	{
		/***
		* @brief Inicizaliza as estruturas da fase no construtor
		* @details Cria as estruturas e adiciona na lista de obstaculos
		* @return void
		*/
		for (int i = 0; i <= 30; i++) {
			obstaculos.push_back(new Entidades::Obstaculos::Plataforma(sf::Vector2f(100.f, 100.f), sf::Vector2f(100 * i, 670)));
		}
	}






}