#pragma once
#include "Ente.h"
#include "Directions.h"
/**
*	Felipe Simbalista: 25/05/2025
* 
* Classe abstrata Entity
* 
*	Representa todos os objetos desenhaveis dentro de um estado
* 
*	Em menuState representa botões
* 
*	Em GameState representa obstaculos/personagens/projeteis
* 
*	Inicializa a posição e o tamanho do shape da entidade
*
*/
namespace Entidades{
	class Entity : public Ente
	{
	protected:
		sf::Vector2f position;
		sf::Vector2f shapeSize;
		sf::RectangleShape shape;
		sf::Vector2f speed;
	public:
		const sf::Vector2f getCenter();
		const sf::Vector2f getPosition();
		void move();
		void changeSpeed(sf::Vector2f addSpeed);
		virtual void executar() = 0;
		const virtual sf::FloatRect getBounds();
		Entity();
		Entity(sf::Vector2f size, sf::Vector2f pos);
		~Entity();
	};

}