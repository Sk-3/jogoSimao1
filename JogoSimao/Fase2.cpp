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
		pGerGraphic->setView(view);
		handleEvent();

		view.setCenter(player->getPosition());


		listaEntidades.executar();
		colision.executar();
		gravity.executar();
		listaEntidades.desenhar();
		hud.executar();
		hud.draw();


	}

	void Fase2::criarInimigos() {
		/***
		* @brief Inicizaliza os inimigos da fase no construtor
		* @details Cria os inimigos e adiciona na lista de personagens
		* @return void
		*/

	
	}


	void Fase2::criarEstruturas() {
		/***
		* @brief Inicizaliza as estruturas da fase no construtor
		* @details Cria as estruturas e adiciona na lista de obstaculos
		* @return void
		*/
		for (int i = 0; i <= 2; i++) {
			Entidades::Obstaculos::Plataforma* plat1 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(100.f, 100.f), sf::Vector2f(100 * i, 670));
			obstaculos.push_back(plat1);				
			listaEntidades.inserirNoFim(plat1);
			Entidades::Obstaculos::Plataforma* plat2 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(100.f, 100.f), sf::Vector2f((100 * i)+1100, 670));
			obstaculos.push_back(plat2);
			listaEntidades.inserirNoFim(plat2);

		}

		Entidades::Obstaculos::PlataformaTeste* platT1 = new Entidades::Obstaculos::PlataformaTeste(sf::Vector2f(100.f, 100.f), sf::Vector2f(500, 500), -4);
		obstaculos.push_back(platT1);
		listaEntidades.inserirNoFim(platT1);

		Entidades::Obstaculos::PlataformaTeste* platT2 = new Entidades::Obstaculos::PlataformaTeste(sf::Vector2f(100.f, 100.f), sf::Vector2f(700, 500), 4);
		obstaculos.push_back(platT2);
		listaEntidades.inserirNoFim(platT2);


	}
}
