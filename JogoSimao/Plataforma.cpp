#include "Plataforma.h"
namespace Entidades{
	namespace Obstaculos {
		Plataforma::Plataforma(sf::Vector2f size, sf::Vector2f pos)
			:Obstaculo(size, pos)
		{
			colidivel = 1;
		}

		Plataforma::Plataforma()
		{

		}

		Plataforma::~Plataforma()
		{
		}

		void Plataforma::obstacular(Personagens::Character* pPlayer)
		{
			/**
			*
			*/
		}

		void Plataforma::executar()
		{

			//se esta colidindo, muda a cor pra vermelho, caso contrário fica branco
			if (isColiding) {
				shape.setFillColor(sf::Color::Red);
			}
			else {
				shape.setFillColor(sf::Color::White);
			}
		}

	}
}