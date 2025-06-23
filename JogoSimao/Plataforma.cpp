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
			obstaculou = false;
			topo = true;
			fundo = true;
		}

		Plataforma::Plataforma()
		{
			colidivel = 1;
			speed.y = 1;
			max = 800;
			min = 300;
			obstaculou = false;
			topo = true;
			fundo = true;
			velocidade = 3;
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