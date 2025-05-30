#include "Entity.h"
namespace Entidades{

	const sf::Vector2f Entity::getPosition()
	{
		return shape.getPosition();
	}

	void Entity::move()
	{
	
		shape.move(speed);
	}

	void Entity::changeSpeed(sf::Vector2f addSpeed)
	{
		speed += addSpeed;
	}

	const sf::FloatRect Entity::getBounds()
	{
		return shape.getGlobalBounds();
	}

	Entity::Entity():
		position(sf::Vector2f(0.f,0.f)), shapeSize(sf::Vector2f(50.f, 50.f))
	{
	}

	Entity::Entity(sf::Vector2f size, sf::Vector2f pos) :
	position(pos), shapeSize(size)
	{
		shape.setSize(shapeSize);
		shape.setPosition(pos);
	}

	Entity::~Entity()
	{
	}

}