#include "Atirador.h"


namespace Entidades{
	namespace Personagens
	{
		Personagens::Atirador::Atirador(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis, std::vector<Character*>* personagens) :
			Inimigo(size, pos, player, projeteis), personagens(personagens)
		{
			arma = new Arma(pProjeteis, this, 0.5);

			inicializarCachorros();

			Clocktiro.restart();
			range = 1000;
			shape.setFillColor(sf::Color::Magenta);
			health = 30;
			tipo = TipoPersonagem::INIMIGO;
		}
		Atirador::~Atirador()
		{
		}

		void Atirador::inicializarCachorros()
		{
			sf::Vector2f posCachorro = getPosition();
			posCachorro.x -= 50;
			Cachorro* tempCachorro = new Cachorro(sf::Vector2f(100, 50), posCachorro, pPlayer, pProjeteis, this);
			cachorros.emplace_back(tempCachorro);
			personagens->emplace_back(tempCachorro);
			posCachorro.x += 100;
			tempCachorro = new Cachorro(sf::Vector2f(100, 50), posCachorro, pPlayer, pProjeteis, this);
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
					cach->mandarAtacar();
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