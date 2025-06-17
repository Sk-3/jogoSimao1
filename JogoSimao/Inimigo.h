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
			std::set<Projetil*>* pProjeteis;
			Personagem* pJogador;
			float range;
		public:
			Inimigo(sf::Vector2f pos, Listas::ListaEntidades* lista, Personagem* pJogador);
			~Inimigo();
			
			//GETTERS
			const Personagem* getJogador() const;
			//SETTERS
	


			virtual void executar() = 0;
			void atirar();
			virtual void perseguirJogador();
			virtual bool jogadorNoAlcance();
		};
	}
}