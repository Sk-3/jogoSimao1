#include "Entity.h"
namespace Entidades{
	const sf::Vector2f Entity::getCenter()
	{
		sf::Vector2f center;

		center.x = shape.getGlobalBounds().left + shape.getGlobalBounds().width / 2.f;

		center.y = shape.getGlobalBounds().top + shape.getGlobalBounds().height / 2.f;

		return center;
	}
	const sf::Vector2f Entity::getPosition()
	{
		/***
		* @brief retorna a posicao do corpo do objeto
		* @return sf::Vector2f - posicao do corpo do objeto
		*/
		return shape.getPosition();
	}

	void Entity::move()
	{
		/***
		* @brief move o corpo do objeto na direcao do vetor speed
		*/
		shape.move(speed);
	}

	void Entity::changeSpeed(sf::Vector2f addSpeed)
	{
		/***
		* @brief altera a velocidade do corpo do objeto
		* @param addSpeed - vetor que sera adicionado a velocidade atual do corpo do objeto
		*/
		speed += addSpeed;
	}

	const sf::FloatRect Entity::getBounds()
	{
		/***
		* @brief retorna o retangulo delimitador do corpo do objeto
		* @return sf::FloatRect - retangulo delimitador do corpo do objeto
		*/
		return shape.getGlobalBounds();
	}

	Entity::Entity():
		position(sf::Vector2f(0.f,0.f))
	{
	}

	Entity::Entity(sf::Vector2f size, sf::Vector2f pos) :
	position(pos)
	{

		/***
		* @brief construtor da classe Entity, inicializa o corpo do objeto com a posicao e tamanho especificados
		* @param pos - posicao do corpo do objeto
		*/

		
		shape.scale(3,3);
		shape.setPosition(pos);
		shape.setTexture(*pGerGraphic->getProjetilTexture());
		setFigura(&shape);
	}

	Entity::~Entity()
	{
	}

}