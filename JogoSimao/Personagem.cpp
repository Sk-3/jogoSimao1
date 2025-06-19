#include "Personagem.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "Arma.h"
namespace Entidades{
	namespace Personagens{
		Personagem::Personagem()
			:Entidade()
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

		Personagem::Personagem(sf::Vector2f pos )
			:Entidade(pos)
		{
			/***
			*@brief Construtor da classe Character, que inicializa o personagem com tamanho e posicaoo especificos.
			*@param size Tamanho do personagem.
			*@param pos Posicao inicial do personagem.
			*
			*/
			arma = nullptr;
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

		Personagem::~Personagem()
		{
			if (arma) {
				delete arma;
			}
		}

		
		
		//GETTERS

		const TipoPersonagem Personagem::getTipo() const
		{
			return tipo;
		}

		const float Personagem::getTiroCoooldown() const
		{
			return tiroCooldown;
		}
		const bool Personagem::vivo() const
		{
			return (health > 0);
		}
		const Directions Personagem::getDirection() const
		{
			return direction;
		}
		const int Personagem::getHealth() const
		{
			return health;
		}

		const float Personagem::getClockTiro() const
		{
			return Clocktiro.getElapsedTime().asSeconds();
		}


		//SETTERS


		void Personagem::colidiu(Entidade* entidade, Directions direction)
		{
			switch (direction) {
			case Directions::DOWN: {
				speed.y = 0;
				shape.setPosition(shape.getPosition().x, (entidade->getBounds().top - getBounds().height));
				jumps = 2;
				break;
			}
			case Directions::UP: {
				speed.y = 0;
				shape.setPosition(getBounds().left, entidade->getBounds().top + entidade->getBounds().height);
				break;
			}
			case Directions::LEFT: {
				speed.x = 0;
				shape.setPosition(entidade->getBounds().left + entidade->getBounds().width, getBounds().top);
				if (jumps == 0) {
					jumps = 1;
				}
				break;
			}
			case Directions::RIGHT: {
				speed.x = 0;
				shape.setPosition(entidade->getBounds().left - getBounds().width, getBounds().top);
				if (jumps == 0) {
					jumps = 1;
				}
				break;
			}
			default: {
				break;
			}
			}
		}

		void Personagem::caiuDoMapa()
		{
			if (getPosition().y > 1500) {
				health--;
			}
		}

		void Personagem::tiraVida(int dano)
		{
			health -= dano;
		}

		void Personagem::resetClockTiro()
		{
			Clocktiro.restart();
		}
		void Personagem::setMoveSpeed(float moveSpeed)

		{
			this->moveSpeed = moveSpeed;
		}
		void Personagem::atirar(Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao) {
			arma->atirar(listaEntidade, gerenciadorColisao);
		}

		void Personagem::executar() {
			move();
		}

	}
}