#include "Player.h"
#include "Projetil.h"
#include "Arma.h"
namespace Entidades{
	namespace Personagens{
		Player::Player()
			:Personagem()
		{
			tipo = TipoPersonagem::PLAYER;
			jumps = 2;

			position = sf::Vector2f(300.f, 0.f);
			shape.setPosition(position);
			maxSpeed = 6;

			shape.setTexture(*pGerGraphic->getPlayerTexture());
			
		}

		Player::Player(sf::Vector2f size, sf::Vector2f pos, std::vector<Projetil*>* projeteis)
			:Personagem(size, pos)
		{
			arma = new Arma(projeteis, this, Armas::METRALHADORA);
			tipo = TipoPersonagem::PLAYER;
			maxSpeed = 6;
			jumps = 2;
			shape.setTexture(*pGerGraphic->getPlayerTexture());
			shape.setTextureRect(sf::IntRect(0, 0, 16, 16));
			setFigura(&shape);

		}

		Player::~Player()
		{
			
		}

		sf::Vector2f Player::getPosition()
		{
			return shape.getPosition();
		}

		void Player::moveUp()
		{
			if (jumps) {
				speed.y = -8;
				jumps--;
			}
	
	
		}

		void Player::moveDown()
		{
			direction = Directions::DOWN;
			speed.y += 0.3;
		}

		void Player::moveLeft()
		{
			direction = Directions::LEFT;
			if(speed.x >= -maxSpeed) {
				speed.x -= 0.4;
			}
		}

		void Player::moveRight()
		{
			direction = Directions::RIGHT;
			if (speed.x <= maxSpeed) {
				speed.x += 0.4;
			}
		}

		void Player::dash()
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

		void Player::stopAxisX()
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

		void Player::executar()
		{
			//move o player a atualiza a posição da camera
			if (direction == Directions::LEFT) {
				shape.setScale(-5, 5);
				//	shape.setOrigin(getBounds().width, 0);
				
			}
			else {
				shape.setOrigin(0,0);
				shape.setScale(5, 5);
			}
			move();
		}

		void Player::atirar()
		{
			arma->atirar();
		}

		

	}
}