#include "Fase.h"
namespace Fases{

	Fase::Fase():
		State(),
		gravity(&listaEntidades),
		GC(&listaEntidades),
		player(new Entidades::Personagens::Jogador(sf::Vector2f(100, 100), &listaEntidades)),
		view(pGerGraphic->getStdView())
	{
		characters = listaEntidades.getPersonagens();
		projeteis = listaEntidades.getProjeteis();
		estruturas = listaEntidades.getEstruturas();
		obstaculos = listaEntidades.getObstaculos();
		id = 0;
		hud.setPlayer(player);
		player2 = nullptr;
		pGerGraphic->setView(view);
		listaEntidades.inserirNoFim(player);
	}

	

	Fase::~Fase() {
		listaEntidades.desalocar();

	}

	void Fase::handleEvent()
	{
		/**
		* @brief Gerencia os eventos de teclado
		* @details Verifica as teclas pressionadas e executa as ações correspondentes para o jogador e o jogador 2 (se existir).
		* @return void
		*/
		//Ações do jogador secundario
		if (player2) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				player2->moveLeft();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				player2->moveRight();
			}
			else {
				player2->stopAxisX();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

				player2->moveUp();

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				player2->moveDown();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
				player2->dash();
			}
		}

		//Ações do jogador principal
		if(player){
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				player->moveLeft();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				player->moveRight();
			}
			else {
				player->stopAxisX();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				player->moveUp();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				player->moveDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
				player->dash();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				player->atirar();
			}
		}
		sf::Event ev;
		while (window->pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				pGerGraphic->close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::P) {
					if (!player2) {
						listaEntidades.inserirNoFim(new Entidades::Personagens::Jogador(sf::Vector2f(100, 100), &listaEntidades));
					}
				}
				if (ev.key.code == sf::Keyboard::Escape) {
					setAction(Actions::PAUSE);
				}

				break;
			case sf::Event::MouseButtonPressed:
				if (ev.mouseButton.button == sf::Mouse::Left) {
					//mouseClick();
				}
			}
		}
	}

	void Fase::executarJanela()
	{
		/**
		* @brief Executa a janela
		* @details Limpa a janela, define a view e atualiza o centro da view com a posição do jogador.
		* @return void
		*/
		window->clear();
		pGerGraphic->desenharBackground();
		pGerGraphic->setView(view);
		view.setCenter(player->getPosition());
	}

	
	void Fase::criarInimFaceis()
	{
		listaEntidades.inserirNoFim(new Entidades::Personagens::Cachorro(sf::Vector2f(3500, 300), &listaEntidades, player, NULL));
	}

	void Fase::criarPlataformas()
	{
		listaEntidades.inserirNoFim(new Entidades::Obstaculos::Plataforma(sf::Vector2f(900, 600), -3 - id, 800, 300));
 
		listaEntidades.inserirNoFim(new Entidades::Obstaculos::Plataforma(sf::Vector2f(1100, 500), 3 + id, 800, 300));
 
		listaEntidades.inserirNoFim(new Entidades::Obstaculos::Plataforma(sf::Vector2f(1300, 400), -3 - id, 800, 300));
 
		listaEntidades.inserirNoFim(new Entidades::Obstaculos::Plataforma(sf::Vector2f(1500, 400), 3 + id, 800, 300));
	}

	void Fase::criarCenario()
	{
		for (int i = 0; i < 15; i++) {

			  
			listaEntidades.inserirNoFim(new Entidades::Estrutura(sf::Vector2f((100 * i) - 700, 670), TipoEstrutura::CHAO));
 
		}

		  
		listaEntidades.inserirNoFim(new Entidades::Estrutura(sf::Vector2f(1700, 638), TipoEstrutura::CHAO));
		 

		for (int i = 0; i < 20; i++) {

			  
			listaEntidades.inserirNoFim(new Entidades::Estrutura(sf::Vector2f((100 * i) + 1800, 670), TipoEstrutura::CHAO));
			 
		}

		for (int i = 0; i < 30; i++) {

			  
			listaEntidades.inserirNoFim(new Entidades::Estrutura(sf::Vector2f((100 * i) + 4800, 670), TipoEstrutura::CHAO));
			 
		}

		for (int i = 0; i < 3; i++) {
			  
			listaEntidades.inserirNoFim(new Entidades::Estrutura(sf::Vector2f(-400 + (-100 * i), (-330 + 670)), TipoEstrutura::PAREDE));
			  
			listaEntidades.inserirNoFim(new Entidades::Estrutura(sf::Vector2f(7500 + (100 * i), (-330 + 670)), TipoEstrutura::PAREDE));

		}
	}

}
