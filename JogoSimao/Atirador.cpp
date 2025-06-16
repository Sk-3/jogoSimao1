#include "Atirador.h"
#include <iostream>

namespace Entidades{
	namespace Personagens
	{
		Personagens::Atirador::Atirador(sf::Vector2f pos,Listas::ListaEntidades* lista ,Personagem* player) :
			Inimigo(pos, lista,player), personagens(personagens)
		{
			arma = new Arma(lista, this, Armas::RIFLE);
			Clocktiro.restart();
			range = 1000;
			health = 30;
			tipo = TipoPersonagem::INIMIGO;
		}
		Atirador::~Atirador()
		{
		}
		void Atirador::eliminarCachorros()
		{
			std::vector<Cachorro*> novoArray;
			for (const auto& cachorro : cachorros) {
				if (cachorro->vivo()) {
					novoArray.emplace_back(cachorro);
				}
			}

			cachorros = novoArray;
		}

		void Atirador::executar() {
			/**
			*@brief Executa o atirador
			*@return void
			*/
			//eliminarCachorros();
			if (!vivo()) {
				desativar();
			}
			if (jogadorNoAlcance()) {
				for (const auto& cach : cachorros) {
					cach->mandarAtacar();
				}

				if (pPlayer->getCenter().x > getCenter().x) {
					direction = Directions::RIGHT;
				}
				else {
					direction = Directions::LEFT;
				}
				atirar();

			}
			else {
				for (const auto& cach : cachorros) {
					cach->mandarSeguir();
				}
			}

			move();
		}
	}
	
}