#pragma once
#include "Personagem.h"
/**
*	Felipe Simbalista: 25/05/2025
*	Classe abstrata inimigo
*/

namespace Entidades{
	namespace Personagens{
		class Inimigo : public Personagem
		{
		protected:
			static int quantidadeInimigos;
			int nivel_maldade;
			Personagem* pPlayer;
			Listas::ListaEntidades* listaEntidade;
			Gerenciadores::GerenciadorColisao* gerColisao;
			float range;
		public:
			Inimigo(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao);
			~Inimigo();
			
			//GETTERS
			const Personagem* getPlayer() const;
			static const int getQuantidadeInimigos();
			//SETTERS
	
			void diminuirInimigos();
			void aumentarPontos();
			virtual void executar() = 0;
			virtual void perseguirJogador();
			virtual bool jogadorNoAlcance();
		};
		
	}


}