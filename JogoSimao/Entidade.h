#pragma once
#include "Ente.h"
#include "Directions.h"
#include "TipoEntidade.h"
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
		std::ostream* buffer;
		bool ativo;
	public:

		Entidade();
		Entidade(sf::Vector2f pos);
		~Entidade();
		//GETTERS
		virtual const TipoEntidade getTipoEntidade() const = 0;
		const sf::Vector2f getCenter();
		const sf::Vector2f getPosition();
		const virtual sf::FloatRect getBounds();
		const bool Ativado();
		//SETTERS
		void move();
		void changeSpeed(sf::Vector2f addSpeed);
		void desativar();
		//void salvarDataBuffer();
		//virtual void salvar() = 0;
		virtual void executar() = 0;
		
	};

}