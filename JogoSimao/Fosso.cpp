#include "Fosso.h"
namespace Entidades {
	namespace Obstaculos {

		Entidades::Obstaculos::Fosso::Fosso(sf::Vector2f pos, float largura)
			:Obstaculo(pos)
		{
			id = Id::Fosso;
			obstaculou = false;
			this->largura = largura;
			shape.setTexture(*pGerGraphic->getChaoTexture());
			shape.setTextureRect(sf::IntRect(192, 128, 96, 32));
			shape.setScale(1.1 * largura, 1.1);
		}

		Entidades::Obstaculos::Fosso::Fosso()
		{
			obstaculou = false;
			this->largura = 1;
		}

		Entidades::Obstaculos::Fosso::~Fosso()
		{
		}

		void Fosso::obstacular(Personagens::Personagem* pPersonagem)
		{
			if (pPersonagem->getTipo() == TipoPersonagem::PLAYER) {
				obstaculou = true;
			}
		}

		void Fosso::antigravidade()
		{
			speed.y = 0;
		}

		void Fosso::desabar()
		{
			if (!obstaculou) {
				antigravidade();								
			}
			else
			{
				speed.y = 5;
			}
		}		
		
		void Fosso::executar()
		{
			desabar();
			move();
		}

		void Fosso::salvar() {
			salvarFosso();
		}
		void Fosso::salvarFosso()
		{
			salvarObstaculo();
			buffer << largura << " " << obstaculou;
			std::cout << buffer.str() <<"\n";
		}
	}
}