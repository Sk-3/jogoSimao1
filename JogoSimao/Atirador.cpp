#include "Atirador.h"


namespace Entidades{
	namespace Personagens
	{
		Personagens::Atirador::Atirador(sf::Vector2f pos, Personagem* player, std::vector<Projetil*>* projeteis, std::vector<Personagem*>* personagens) :
			Inimigo(pos, player, projeteis), personagens(personagens)
		{
			arma = new Arma(pProjeteis, this, Armas::RIFLE);

			inicializarCachorros();

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

		void Atirador::inicializarCachorros()
		{
			sf::Vector2f posCachorro = getPosition();
			posCachorro.x -= 50;
			Cachorro* tempCachorro = new Cachorro( posCachorro, pPlayer, pProjeteis, this);
			cachorros.emplace_back(tempCachorro);
			personagens->emplace_back(tempCachorro);
			posCachorro.x += 100;
			tempCachorro = new Cachorro(posCachorro, pPlayer, pProjeteis, this);
			cachorros.emplace_back(tempCachorro);
			personagens->emplace_back(tempCachorro);
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
			eliminarCachorros();
			if (jogadorNoAlcance()) {
				for (const auto& cach : cachorros) {
					cach->mandarCacar();
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