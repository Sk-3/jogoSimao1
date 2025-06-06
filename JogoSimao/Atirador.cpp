#include "Atirador.h"


namespace Entidades{
	namespace Personagens
	{
		Personagens::Atirador::Atirador(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis, std::vector<Character*>* personagens) :
			Inimigo(size, pos, player, projeteis), personagens(personagens)
		{

			sf::Vector2f posCachorro = pos;
			
			

			pos.x -= 50;

			Cachorro* tempCachorro = new Cachorro(size, posCachorro, player, projeteis, this);
			cachorros.emplace_back(tempCachorro);
			personagens->emplace_back(tempCachorro);
			pos.x += 100;
			tempCachorro = new Cachorro(size, posCachorro, player, projeteis, this);
			cachorros.emplace_back(tempCachorro);
			personagens->emplace_back(tempCachorro);
			Clocktiro.restart();
			range = 1000;
			shape.setFillColor(sf::Color::Magenta);
			health = 30;
			tipo = TipoPersonagem::INIMIGO;
		}
		Atirador::Atirador()
		{
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
			eliminarCachorros();
			if (jogadorNoAlcance()) {
				for (const auto& cach : cachorros) {
					cach->mandarAtacar();
				}

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