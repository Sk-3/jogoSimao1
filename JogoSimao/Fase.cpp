#include "Fase.h"
namespace Fases{

	Fase::Fase():
		State(),
		player(new Entidades::Personagens::Jogador(sf::Vector2f(100, 100))),
		view(pGerGraphic->getStdView())
	{
		gerenciadorColisao.incluirJogador1(player);
		listaEntidades.inserirNoFim(player);
		id = 0;
		hud.setPlayer(player);
		player2 = nullptr;
		pGerGraphic->setView(view);
		
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
				player->atirar(&listaEntidades,&gerenciadorColisao);
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
						player2 = new Entidades::Personagens::Jogador(sf::Vector2f(100, 100));
						listaEntidades.inserirNoFim(player2);
						gerenciadorColisao.incluirJogador2(player2);
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

	void Fase::criarCachorro()
	{
		Entidades::Personagens::Cachorro* cachorro = new Entidades::Personagens::Cachorro(sf::Vector2f(3500, 300), player, &listaEntidades, &gerenciadorColisao, NULL);
		listaEntidades.inserirNoFim(cachorro);
		gerenciadorColisao.incluirInimigo(cachorro);

	}

	void Fase::criarPlataformas()
	{
		Entidades::Obstaculos::Plataforma* plat1 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(900, 600), -3 -id, 800, 300);
		obstaculos.push_back(plat1);
		listaEntidades.inserirNoFim(plat1);
		gerenciadorColisao.incluirObstaculo(plat1);

		Entidades::Obstaculos::Plataforma* plat2 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(1100, 500), 3 + id, 800, 300);
		obstaculos.push_back(plat2);
		listaEntidades.inserirNoFim(plat2);
		gerenciadorColisao.incluirObstaculo(plat2);

		Entidades::Obstaculos::Plataforma* plat3 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(1300, 400), -3 - id, 800, 300);
		obstaculos.push_back(plat3);
		listaEntidades.inserirNoFim(plat3);
		gerenciadorColisao.incluirObstaculo(plat3);

		Entidades::Obstaculos::Plataforma* plat4 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(1500, 400), 3 + id, 800, 300);
		obstaculos.push_back(plat4);
		listaEntidades.inserirNoFim(plat4);
		gerenciadorColisao.incluirObstaculo(plat4);
	}

	void Fase::criarCenario()
	{
		for (int i = 0; i < 15; i++) {

			Entidades::Estrutura* estrutura = new Entidades::Estrutura(sf::Vector2f((100 * i) - 700, 670), TipoEstrutura::CHAO);
			listaEntidades.inserirNoFim(estrutura);
			gerenciadorColisao.incluirEstrutura(estrutura);
		}

		Entidades::Estrutura* parada = new Entidades::Estrutura(sf::Vector2f(1700, 638), TipoEstrutura::CHAO);
		listaEntidades.inserirNoFim(parada);
		gerenciadorColisao.incluirEstrutura(parada);

		for (int i = 0; i < 20; i++) {

			Entidades::Estrutura* estrutura = new Entidades::Estrutura(sf::Vector2f((100 * i) +1800, 670), TipoEstrutura::CHAO);
			listaEntidades.inserirNoFim(estrutura);
			gerenciadorColisao.incluirEstrutura(estrutura);
		}

		for (int i = 0; i < 30; i++) {

			Entidades::Estrutura* estrutura = new Entidades::Estrutura(sf::Vector2f((100 * i) + 4800, 670), TipoEstrutura::CHAO);
			listaEntidades.inserirNoFim(estrutura);
			gerenciadorColisao.incluirEstrutura(estrutura);
		}

		for (int i = 0; i < 3; i++) {

			Entidades::Estrutura* parede1 = new Entidades::Estrutura(sf::Vector2f(-400 + (-100 * i), (-330 + 670)), TipoEstrutura::PAREDE);
			
			listaEntidades.inserirNoFim(parede1);
			gerenciadorColisao.incluirEstrutura(parede1);

			Entidades::Estrutura* parede2 = new Entidades::Estrutura(sf::Vector2f(7500 + (100 * i), (-330 + 670)), TipoEstrutura::PAREDE);
			listaEntidades.inserirNoFim(parede2);
			gerenciadorColisao.incluirEstrutura(parede2);
		}
	}

	void Fase::aplicarGravidade()
	{
		for (Lista<Entidades::Entidade*>::Iterator it = listaEntidades.inicio(); it != listaEntidades.fim(); ++it) {
			(*it)->changeSpeed(sf::Vector2f(0, 0.2));
		}
	}

}
