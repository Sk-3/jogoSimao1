#include "Plataforma.h"
namespace Entidades{
	namespace Obstaculos {
		Plataforma::Plataforma(sf::Vector2f pos, float vel, float h_Max, float h_Min)
			:Obstaculo(pos)
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
			obstaculou = false;
		}

		Plataforma::Plataforma()
		{
			colidivel = 1;
			speed.y = 1;
			max = 800;
			min = 300;
			topo = false;
			fundo = false;
			obstaculou = false;
		}

		Plataforma::~Plataforma()
		{
		}

		void Plataforma::obstacular(Personagens::Personagem* pPersonagem)
		{
			if (!obstaculou) {
				if (pPersonagem->getTipo() == TipoPersonagem::PLAYER)
				{
					speed.y *= 1.7;
				}
				obstaculou = true;
			}
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