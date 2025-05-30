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
			dispararProjetil(player);
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

	void GameState::dispararProjetil(Entidades::Personagens::Character* character)
	{
		sf::Vector2f position = character->getPosition();
		position.y += (character->getBounds().height / 2);

		if (character->getDirection() != Directions::LEFT) {
			position.x += character->getBounds().width;
		
		}

		projeteis.push_back(new Entidades::Projetil(sf::Vector2f(10.0, 10.0), position, character->getDirection()));
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