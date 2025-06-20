#pragma once
#include "Personagem.h"
#include "Jogador.h"

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
			Jogador* pJogador;
			Listas::ListaEntidades* listaEntidade;
			Gerenciadores::GerenciadorColisao* gerColisao;
			float range;
		public:
			Inimigo(sf::Vector2f pos, Jogador* pJogador, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao);
			~Inimigo();
			
			//GETTERS
			Jogador* getJogador();
			static int getQuantidadeInimigos();
			//SETTERS
			static void zerarInimigos();
			void diminuirInimigos();
			void aumentarPontos();
			virtual void executar() = 0;
			virtual void danificar(Jogador* pJogador) = 0;
			virtual void perseguirJogador();
			virtual bool jogadorNoAlcance();
		};
		
	}


}