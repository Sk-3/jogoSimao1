#pragma once
#include "Ente.h"
#include "Directions.h"
#include <ostream>
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
		sf::Sprite shape;
		sf::Vector2f speed;
		std::ostream* buffer;
	public:

		Entity();
		Entity(sf::Vector2f size, sf::Vector2f pos);
		~Entity();
		//GETTERS
		const sf::Vector2f getCenter();
		const sf::Vector2f getPosition();
		const virtual sf::FloatRect getBounds();
		//SETTERS
		void move();
		void changeSpeed(sf::Vector2f addSpeed);
		
		//void salvarDataBuffer();
		//virtual void salvar() = 0;
		virtual void executar() = 0;
		
	};

}