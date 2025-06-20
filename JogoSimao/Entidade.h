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
	class Entidade : public Ente
	{
	protected:
		sf::Vector2f position;
		sf::Sprite shape;
		sf::Vector2f speed;
		bool ativo;
		std::ostream* buffer;
	public:

		Entidade();
		Entidade(sf::Vector2f pos);
		~Entidade();
		//GETTERS
		const sf::Vector2f getCenter();
		const sf::Vector2f getPosition();
		const virtual sf::FloatRect getBounds();
		bool ativado() const;
		//SETTERS
		void desativar();
		void move();
		void changeSpeed(sf::Vector2f addSpeed);
		
		void salvarEntidade();
		//virtual void salvar() = 0;
		virtual void executar() = 0;
		
	};

}