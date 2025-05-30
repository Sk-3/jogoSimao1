#include "Fase2.h"
namespace Fases{
	Fase2::Fase2():
	GameState()
	{
		//Criação das plataformas da fase
		
			for (int i = 0; i <= 30; i++) {
				obstaculos.push_back(new Entidades::Plataforma(sf::Vector2f(100.f, 100.f), sf::Vector2f(100 * i, 670)));
			}

	}

	Fase2::~Fase2()
	{
	}

	void Fase2::executar()
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


	}





}
