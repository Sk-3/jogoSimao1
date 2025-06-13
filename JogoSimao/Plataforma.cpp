#include "Plataforma.h"
namespace Entidades{
	namespace Obstaculos {
		Plataforma::Plataforma(sf::Vector2f size, sf::Vector2f pos, float vel, float h_Max, float h_Min)
			:Obstaculo(size, pos)
		{
			colidivel = 1;
			shape.setTexture(*pGerGraphic->getChaoTexture());
			shape.setTextureRect(sf::IntRect(192, 96, 96, 32));			
			shape.setScale(1.1, 1.1);
			speed.y = vel;
			max = h_Max;
			min = h_Min;
			topo = false;
			fundo = false;
		}

		Plataforma::Plataforma()
		{

		}

		Plataforma::~Plataforma()
		{
		}

		void Plataforma::obstacular(Personagens::Personagem* pPlayer)
		{
			/**
			*
			*/
		}
		void Plataforma::mover()
		{
			if (getPosition().y > max)
			{
				fundo = true;
			}

			if (getPosition().y < min) {
				topo = true;
			}

			if (topo)
			{
				speed.y *= -1;
				topo = false;
			}

			if (fundo)
			{
				speed.y *= -1;
				fundo = false;
			}

			move();
		}


		void Plataforma::executar()
		{			
			mover();
		}

	}
}