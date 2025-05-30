#include "Character.h"
#include "Obstaculo.h"

namespace Entidades{
	namespace Personagens{
		Character::Character()
			:Entity()
		{
			jumps = 2;
			health = 10;
			power = 0;
			speed.x = 0;
			speed.y = 0;
			direction = Directions::RIGHT;
		}

		Character::Character(sf::Vector2f size, sf::Vector2f pos)
			:Entity(size, pos)
		{
			tipo = TipoPersonagem::INMIGO; 
			maxSpeed = 6;
			moveSpeed = 120;
			jumps = 2;
			health = 10;
			power = 0;
			speed.x = 0;
			speed.y = 0;
			direction = Directions::RIGHT;
		}

		Character::~Character()
		{
		}

		void Character::hitTop(Obstaculos::Obstaculo* obstaculo)
		{
			speed.y = 0;
			shape.setPosition(getBounds().left, obstaculo->getBounds().top + obstaculo->getBounds().height);
		}

		void Character::hitGround(Obstaculos::Obstaculo* obstaculo)
		{
			speed.y = 0;
			shape.setPosition(getBounds().left, (obstaculo->getBounds().top - getBounds().height));
			jumps = 2;
		}

		void Character::hitLeft(Obstaculos::Obstaculo* obstaculo)
		{
			speed.x = 0;
			shape.setPosition(obstaculo->getBounds().left + obstaculo->getBounds().width, getBounds().top);
			if (jumps == 0) {
				jumps = 1;
			}
		}

		void Character::hitRight(Obstaculos::Obstaculo* obstaculo)
		{
	
			speed.x = 0;
			shape.setPosition(obstaculo->getBounds().left - getBounds().width, getBounds().top);
			if (jumps == 0) {
				jumps = 1;
			}
		}

		void Character::tiraVida(int dano)
		{
			health -= dano;
		}

		const TipoPersonagem Character::getTipo() const
		{
			return tipo;
		}

		const Directions Character::getDirection() const
		{
			return direction;
		}
		const int Character::getHealth() const
		{
			return health;
		}
		void Character::executar() {
			move();
		}
		void Character::draw()
		{
			pGerGraphic->getWindow()->draw(shape);
		}
		const bool Character::vivo() const
		{
			return (health > 0);
		}
	}
}