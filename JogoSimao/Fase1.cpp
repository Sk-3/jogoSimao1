#include "Fase1.h"

namespace Fases{
	Fase1::Fase1() :
		GameState()
	{
		//Criação das plataformas da fase

		for (int i = 0; i <= 30; i++) {
			obstaculos.push_back(new Entidades::Obstaculos::Plataforma(sf::Vector2f(100.f, 100.f), sf::Vector2f(100 * i, 670)));
		}


		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(100, 300)));

		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(900, 300)));


		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(300, 300)));

		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(500, 300)));

		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(700, 300)));


	

	}

	Fase1::~Fase1()
	{
	}

	void Fase1::executar()
	{
		//clock.restart();
		window->clear();
		pGerGraphic->getWindow()->setView(view);
		handleEvent();
		view.setCenter(player->getPosition());


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






}