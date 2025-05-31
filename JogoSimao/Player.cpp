#include "Player.h"
#include "Projetil.h"
namespace Entidades{
	namespace Personagens{
		Player::Player() {
			tipo = TipoPersonagem::PLAYER;
			jumps = 2;
			position = sf::Vector2f(300.f, 0.f);

			maxSpeed = 6;
			shape.setSize(sf::Vector2f(100.f, 100.f));
			shape.setFillColor(sf::Color::Blue);
			shape.setPosition(position);
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
			move();
		}

		void Player::draw() {
			pGerGraphic->getWindow()->draw(shape);
		}

		void Player::atirar(std::vector<Projetil*>* projeteis)
		{
			if(getClockTiro() > getTiroCoooldown()){
				sf::Vector2f position = getPosition();
				position.y += (getBounds().height / 2);
				if (getDirection() != Directions::LEFT) {
					position.x += getBounds().width;
				}
				projeteis->push_back(new Projetil(sf::Vector2f(10.0, 10.0), position, getDirection(), tipo));
				resetClockTiro(); 
			}
		}

		

	}
}