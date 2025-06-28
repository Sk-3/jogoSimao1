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
			jogadorDois = 0;
			pontos = 0;
			position = sf::Vector2f(300.f, 0.f);
			shape.setPosition(position);
			maxSpeed = 6;
			shape.setTexture(*pGerGraphic->getTextura(Texturas::player));			
		}

		Jogador::Jogador( sf::Vector2f pos)
			:Personagem( pos)
		{
			jogadorDois = 0;
			id = Id::Jogador;
			pontos = 0;
			arma = new Arma(this, Armas::METRALHADORA);
			tipo = TipoPersonagem::PLAYER;
			maxSpeed = 6;
			health = 55;
			jumps = 2;
			shape.setTexture(*pGerGraphic->getTextura(Texturas::player));
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

		void Jogador::setPontuacao(int pontuacao)
		{
			pontos = pontuacao;
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

		void Jogador::setJogadorDois(bool jg2)
		{
			jogadorDois = jg2;
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
				shape.setTexture(*pGerGraphic->getTextura(Texturas::playerLeft));
				
			}
			else {
				shape.setTexture(*pGerGraphic->getTextura(Texturas::player));
			}
			move();
		}

		std::string Jogador::salvar()
		{
			salvarJogador();
			return buffer.str();
		}
		void Jogador::salvarJogador()
		{
			salvarPersonagem();
			buffer << pontos << " " << jogadorDois;
		}

		void Jogador::resetarJogador()
		{
			setAtivo(1);
			setVelocidade(0,0);
			setVida(55);
			setPosicao(100, 100);
			setPontuacao(0);
			setPulos(2);
		}

		

	}
}