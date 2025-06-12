#include "PlataformaTeste.h"
namespace Entidades {
	namespace Obstaculos {
		PlataformaTeste::PlataformaTeste(sf::Vector2f size, sf::Vector2f pos, float vel)
			:Obstaculo(size, pos)
		{
			colidivel = 1;
			shape.setTexture(*pGerGraphic->getChaoTexture());
			shape.setTextureRect(sf::IntRect(192, 96, 96, 32));
			//top, left, width, height?
			shape.setScale(1.1, 1.1);
			speed.y = vel;
			max = false;
			min = false;
		}

		PlataformaTeste::PlataformaTeste()
		{
			
		}

		PlataformaTeste::~PlataformaTeste()
		{
		}

		void PlataformaTeste::obstacular(Personagens::Personagem* pPlayer)
		{
			
		}

		void PlataformaTeste::mover()
		{
			if (getPosition().y > 800)
			{
				min = true;
			}

			if (getPosition().y < 300) {
				max = true;
			}

			if (max)
			{
				speed.y *= -1;
				max = false;
			}

			if (min)
			{
				speed.y *= -1;
				min = false;
			}
			
			move();
		}

		void PlataformaTeste::executar()
		{			
			mover();
		}
	}
}
