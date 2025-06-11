#pragma once
#include "Personagem.h"
#include "Projetil.h"
/**
*	Felipe Simbalista: 25/05/2025
*	Classe abstrata inimigo
*/
namespace Entidades{
	namespace Personagens{
		class Inimigo : public Personagem
		{
		protected:
			int nivel_maldade;
			std::vector<Projetil*>* pProjeteis;
			Personagem* pPlayer;
			float range;
		public:
			Inimigo(sf::Vector2f size, sf::Vector2f pos, Personagem* player, std::vector<Projetil*>* projeteis);
			~Inimigo();
			
			//GETTERS
			const Personagem* getPlayer() const;
			//SETTERS
	


			virtual void executar() = 0;
			void atirar();
			virtual void perseguirJogador();
			virtual bool jogadorNoAlcance();
		};
	}
}