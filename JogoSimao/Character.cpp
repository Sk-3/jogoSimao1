#include "Character.h"
#include "Obstaculo.h"
#include "Projetil.h"

namespace Entidades{
	namespace Personagens{
		Character::Character()
			:Entity(), Subject()
		{
			Clocktiro.restart();
			tiroCooldown = 0.2;
			jumps = 2;
			health = 10;
			power = 0;
			speed.x = 0;
			speed.y = 0;
			direction = Directions::RIGHT;
		}

		Character::Character(sf::Vector2f size, sf::Vector2f pos)
			:Entity(size, pos), Subject()
		{
			/***
			*@brief Construtor da classe Character, que inicializa o personagem com tamanho e posicaoo especificos.
			*@param size Tamanho do personagem.
			*@param pos Posicao inicial do personagem.
			*
			*/
			tiroCooldown = 0.2;
			tipo = TipoPersonagem::INIMIGO; 
			maxSpeed = 6;
			moveSpeed = 3;
			jumps = 2;
			health = 10;
			power = 0;
			speed.x = 0;
			speed.y = 0;
			direction = Directions::RIGHT;
			setFigura(&shape);
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
		const float Character::getTiroCoooldown() const
		{
			return tiroCooldown;
		}
		const bool Character::vivo() const
		{
			return (health > 0);
		}
		const float Character::getClockTiro() const
		{
			return Clocktiro.getElapsedTime().asSeconds();
		}

		void Character::resetClockTiro()
		{
			Clocktiro.restart();
		}
		void Character::setMoveSpeed(float moveSpeed)

		{
			this->moveSpeed = moveSpeed;
		}
	}
}