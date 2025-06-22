#include "Plataforma.h"
namespace Entidades{
	namespace Obstaculos {
		Plataforma::Plataforma(sf::Vector2f pos, float vel, float h_Max, float h_Min)
			:Obstaculo(pos)
		{
			id = Id::Plataforma;
			velocidade = vel;
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

		float Plataforma::getMax()
		{
			return max;
		}
		float Plataforma::getMin() {
			return min;
		}
		void Plataforma::obstacular(Personagens::Personagem* pPersonagem)
		{
			if (!obstaculou) {
				if (pPersonagem->getTipo() == TipoPersonagem::PLAYER)
				{
					speed.y *= 1.5;
					pPersonagem->changeSpeed(sf::Vector2f(-3, 0));
				}
				obstaculou = true;
			}
		}
		void Plataforma::mover()
		{
			if (speed.y > 25 || speed.y < -25) {
				speed.y *= 0.1;
			}

			if (getPosition().y >= max && speed.y > 0) {
				speed.y *= -1;
			}
			else if (getPosition().y <= min && speed.y < 0) {
				speed.y *= -1;
			}
			/*	if (getPosition().y > max)
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
			}*/

			move();
		}

		void Plataforma::executar()
		{			
			mover();
		}
		std::string Plataforma::salvar()
		{
			salvarPlataforma();
			return buffer.str();
		}
		void Plataforma::salvarPlataforma()
		{
			salvarObstaculo();
			buffer << velocidade << " " << max << " " << min << " " << obstaculou;
		}

	}
}