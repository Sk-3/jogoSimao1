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
		window->clear();
		pGerGraphic->getWindow()->setView(view);
		view.setCenter(player->getPosition());

		
		handleEvent();
		
	
		//dispararProjetil(boss);
		
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
		for (auto const& charact : characters) {
			charact->draw();
		}


		hud.executar();
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

		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(100, 300)));
		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(900, 300)));
		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(300, 300)));
		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(500, 300)));
		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(700, 300)));
		
		boss = new Entidades::Personagens::Boss(sf::Vector2f(200, 200), sf::Vector2f(900, 300), player, &projeteis);
		characters.push_back(boss);
	}

	void Fase1::criarEstruturas()
	{
		for (int i = 0; i <= 30; i++) {
			obstaculos.push_back(new Entidades::Obstaculos::Plataforma(sf::Vector2f(100.f, 100.f), sf::Vector2f(100 * i, 670)));
		}
	}






}