#include "Atirador.h"


namespace Entidades{
	namespace Personagens
	{
		Personagens::Atirador::Atirador(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis, std::vector<Character*>* personagens) :
			Inimigo(size, pos, player, projeteis), personagens(personagens)
		{

			sf::Vector2f posCachorro = pos;
			
			pos.x -= 50;
			cachorros[0] = new Cachorro(size, posCachorro, player, projeteis, this);
			personagens->emplace_back(cachorros[0]);
			pos.x += 100;
			cachorros[1] = new Cachorro(size, posCachorro, player, projeteis, this);
			personagens->emplace_back(cachorros[1]);

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

		void Atirador::executar() {
			/**
			*@brief Executa o atirador
			*@return void
			*/
			if (jogadorNoAlcance()) {
				cachorros[0]->mandarAtacar();
				cachorros[1]->mandarAtacar();

			}
			else {
				cachorros[0]->mandarSeguir();
				cachorros[1]->mandarSeguir();
			}

			move();
		}
	}
	
}