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
			sf::Clock danoContatoRelogio;
			float danoContatoCooldown = 1;
			static int quantidadeInimigos;
			int nivel_maldade;
			Personagem* pPlayer;
			float range;
		public:
			Inimigo(sf::Vector2f pos, Personagem* player);
			~Inimigo();
			
			//GETTERS
			const Personagem* getPlayer() const;
			static int getQuantidadeInimigos();
			//SETTERS
			void setNivelMaldade(int maldade);
			static void zerarInimigos();
			void diminuirInimigos();
			void aumentarPontos();
			void salvarInimigo();
			void setAtivo(bool) override;
			virtual std::string salvar() = 0;
			virtual void executar() = 0;
			virtual void danificar(Jogador* jogador) = 0;
			virtual void perseguirJogador();
			
			virtual bool jogadorNoAlcance();
		};
		
	}


}