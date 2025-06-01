#include "GameState.h"
namespace Fases{

	GameState::GameState():
		State(), gravity(&characters, &projeteis),
		colision(&characters, &obstaculos, &projeteis),
		player(new Entidades::Personagens::Player()), view(pGerGraphic->getStdView())
	{
		hud.setPlayer(player);
		player2 = nullptr;
		pGerGraphic->getWindow()->setView(view);
		characters.push_back(player);
	}

	GameState::~GameState() {
		for (auto& obstacul : obstaculos) {
			delete obstacul;
		}
		for (auto& charact : characters) {
			delete charact;
		}
		for (auto& projetil : projeteis) {
			delete projetil;
		}
	}

	void GameState::handleEvent()
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
				player->atirar(&projeteis);
			}
		}
		sf::Event ev;
		while (window->pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				pGerGraphic->getWindow()->close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::P) {
					if (!player2) {
						player2 = new Entidades::Personagens::Player();
						characters.push_back(player2);
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

	void GameState::executarJanela()
	{
		/**
		* @brief Executa a janela
		* @details Limpa a janela, define a view e atualiza o centro da view com a posição do jogador.
		* @return void
		*/
		window->clear();
		pGerGraphic->getWindow()->setView(view);
		view.setCenter(player->getPosition());
	}

	void GameState::removerProjeteis()
	{
		std::vector<Entidades::Projetil*> projeteisAtivos;
		for (Entidades::Projetil* projet : projeteis) {
			if (projet->Ativado()) {
				projeteisAtivos.push_back(projet);
			}
			else {
				delete projet;
			}
		}
		projeteis = projeteisAtivos;
	}

	void GameState::removerPersonagens()
	{
		std::vector<Entidades::Personagens::Character*> personagensVivos;
		for (Entidades::Personagens::Character* persona : characters) {
			if (persona->vivo()) {
				personagensVivos.push_back(persona);
			}
			else { 
				delete persona;
			}
		}
		characters = personagensVivos;
	}

}
