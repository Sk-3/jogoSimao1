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
			topo = true;
			fundo = true;
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
					speed.y *= 1.2;					
				}
				obstaculou = true;
			}
		}
		void Plataforma::mover()
		{			
			if (topo) {
				if (getPosition().y < min)
				{
					fundo = true;
					topo = false;
					speed.y *= -1;					
				}
			}
			if (fundo) {
				if (getPosition().y > max) {
					topo = true;
					fundo = false;
					speed.y *= -1;					
				}
			}			
			speed.y -= 0.2; // compenssar a gravidade
			move();
		}

		void Plataforma::executar()
		{			
			mover();
		}

	}
}