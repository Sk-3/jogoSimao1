#pragma once
#include "Character.h"
#include "Projetil.h"
/**
*	Felipe Simbalista: 25/05/2025
*	Classe abstrata inimigo
*/
namespace Entidades{
	namespace Personagens{
		class Inimigo : public Character
		{
		protected:
			int nivel_maldade;
			std::vector<Projetil*>* pProjeteis;
			Character* pPlayer;
			float range;
		public:
			Inimigo(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis);
			Inimigo();
			~Inimigo();
			
			//GETTERS
			const Character* getPlayer() const;
			//SETTERS
			
			virtual void executar() = 0;

			virtual void perseguirJogador();
			virtual bool jogadorNoAlcance();
		};
	}
}