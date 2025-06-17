#include "Atirador.h"


namespace Entidades{
	namespace Personagens
	{
		Personagens::Atirador::Atirador(sf::Vector2f pos, Listas::ListaEntidades* lista, Personagem* jogador) :
			Inimigo(pos, lista, jogador), personagens(personagens)
		{
			arma = new Arma(lista, this, Armas::RIFLE);
			Clocktiro.restart();
			range = 1000;
			health = 20;
			tipo = TipoPersonagem::INIMIGO;

			shape.setTexture(*pGerGraphic->getAtiradorTexture());
			shape.setTextureRect(sf::IntRect(0, 0, 46, 71));
			shape.setScale(2, 2);
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
			if (!vivo()) {
				desativar();
			}
			eliminarCachorros();
			if (jogadorNoAlcance()) {
				for (const auto& cach : cachorros) {
					cach->mandarCacar();
				}

				if (pJogador->getCenter().x > getCenter().x) {
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