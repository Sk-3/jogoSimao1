#include "Jogador.h"
#include "Projetil.h"
#include "Arma.h"
#include <iostream>
namespace Entidades{
	namespace Personagens{
		Jogador::Jogador()
			:Personagem()
		{
			ativo = 1;
			tipo = TipoPersonagem::PLAYER;
			jumps = 2;

			position = sf::Vector2f(300.f, 0.f);
			shape.setPosition(position);
			maxSpeed = 6;

			shape.setTexture(*pGerGraphic->getPlayerTexture());
			
		}

		Jogador::Jogador( sf::Vector2f pos)
			:Personagem( pos)
		{
			id = Id::Jogador;
			pontos = 0;
			arma = new Arma(this, Armas::METRALHADORA);
			tipo = TipoPersonagem::PLAYER;
			maxSpeed = 6;
			health = 55;
			jumps = 7;
			shape.setTexture(*pGerGraphic->getPlayerTexture());
			shape.setTextureRect(sf::IntRect(0, 0, 16, 16));
			shape.setScale(5, 5);
			setFigura(&shape);

		}

		Jogador::~Jogador()
		{
			
		}

		sf::Vector2f Jogador::getPosition()
		{
			return shape.getPosition();
		}

		void Jogador::movimentar(Directions direcao)
		{
			switch (direcao){
				case Directions::UP:{
					if (jumps && (RelogioPuloCooldown.getElapsedTime().asSeconds() >= puloCooldown)) {
						RelogioPuloCooldown.restart();
						speed.y = -8;
						jumps--;
					}
						break;
					}
				case Directions::DOWN: {
					direction = Directions::DOWN;
					speed.y += 0.3;
					break;
				}
				case Directions::LEFT: {
					direction = Directions::LEFT;
					if (speed.x >= -maxSpeed) {
						speed.x -= 0.4;
					}
					break;
				}
				case Directions::RIGHT: {
					direction = Directions::RIGHT;
					if (speed.x <= maxSpeed) {
						speed.x += 0.4;
					}
					break;
				}
				default:
				{
					break;
				}

			}
		}

		void Jogador::posicionarNoInicio()
		{
			shape.setPosition(100, 100);
		}

		void Jogador::dash()
		{
			if (dashRelogio.getElapsedTime().asSeconds() > dashCooldown) {
				dashRelogio.restart();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					speed.x = -20;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					speed.x = 20;
				}
				else {
					speed.x = 20;
				}
			}
			
		}

		void Jogador::stopAxisX()
		{
			if (speed.x > maxSpeed) {
				speed.x -= 0.4;
			}
			else if (speed.x < -maxSpeed) {
				speed.x += 0.4;
			}

			if (speed.x != 0) {
				if (speed.x >= 0) {
					if (speed.x - 0.2 < 0) {
						speed.x = 0;
					}else{
						speed.x -= 0.2;
					}
				}
				else {
					if (speed.x + 0.2 > 0) {
						speed.x = 0;
					}
					speed.x += 0.2;
				}
			}
		}

		void Jogador::aumentarPontos()
		{
			pontos++;
		}

		int Jogador::getPontos()
		{
			return pontos;
		}

		void Jogador::executar()
		{
			caiuDoMapa();
			//move o player a atualiza a posição da camera
			if (direction == Directions::LEFT) {
				shape.setTexture(*pGerGraphic->getPlayerInvertido());
				
			}
			else {
				shape.setTexture(*pGerGraphic->getPlayerTexture());
			}
			move();
		}

		void Jogador::salvar()
		{
			salvarJogador();
		}
		void Jogador::salvarJogador()
		{
			salvarPersonagem();
			buffer << pontos;
			std::cout << buffer.str() << "\n";
		}

		

	}
}