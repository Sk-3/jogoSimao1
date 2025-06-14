#include "Jogador.h"
#include "Projetil.h"
#include "Arma.h"
namespace Entidades{
	namespace Personagens{
		Jogador::Jogador()
			:Personagem()
		{
			tipo = TipoPersonagem::PLAYER;
			jumps = 2;

			position = sf::Vector2f(300.f, 0.f);
			shape.setPosition(position);
			maxSpeed = 6;

			shape.setTexture(*pGerGraphic->getPlayerTexture());
			
		}

		Jogador::Jogador( sf::Vector2f pos, std::vector<Projetil*>* projeteis)
			:Personagem( pos)
		{
			arma = new Arma(projeteis, this, Armas::METRALHADORA);
			tipo = TipoPersonagem::PLAYER;
			maxSpeed = 6;
			jumps = 2;
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

		void Jogador::moveUp()
		{
			if (jumps) {
				speed.y = -8;
				jumps--;
			}
	
	
		}

		void Jogador::moveDown()
		{
			direction = Directions::DOWN;
			speed.y += 0.3;
		}

		void Jogador::moveLeft()
		{
			direction = Directions::LEFT;
			if(speed.x >= -maxSpeed) {
				speed.x -= 0.4;
			}
		}

		void Jogador::moveRight()
		{
			direction = Directions::RIGHT;
			if (speed.x <= maxSpeed) {
				speed.x += 0.4;
			}
		}

		void Jogador::dash()
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				speed.x = -20;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				speed.x = 20;
			}
			else {
				speed.x = 0;
				speed.y = 0;
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

		void Jogador::executar()
		{
			//move o player a atualiza a posi��o da camera
			if (direction == Directions::LEFT) {
				shape.setTexture(*pGerGraphic->getPlayerInvertido());
				
			}
			else {
				shape.setTexture(*pGerGraphic->getPlayerTexture());
			}
			move();
		}

		void Jogador::atirar()
		{
			arma->atirar();
		}

		

	}
}