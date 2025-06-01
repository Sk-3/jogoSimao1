#include "Fase2.h"
namespace Fases{
	Fase2::Fase2():
	GameState()
	{
		/***
		* @brief Construtor da fase 2
		* @details Inicializa a fase 2, criando as estruturas e os inimigos
		*/
		criarEstruturas();
		criarInimigos();

	}

	Fase2::~Fase2()
	{
	}

	void Fase2::executar()
	{
		/***
		* @brief Executa a fase 2
		* @details Executa a fase 2, atualizando a tela, os personagens, os obstaculos e as colisões
		* @return void
		*/

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

	void Fase2::criarInimigos() {
		/***
		* @brief Inicizaliza os inimigos da fase no construtor
		* @details Cria os inimigos e adiciona na lista de personagens
		* @return void
		*/
		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(100, 300)));
		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(900, 300)));
		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(300, 300)));

		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(500, 300)));

		characters.push_back(new Entidades::Personagens::Cachorro(sf::Vector2f(100, 100), sf::Vector2f(700, 300)));
	}


	void Fase2::criarEstruturas() {
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
