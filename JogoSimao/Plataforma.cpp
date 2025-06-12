#include "Plataforma.h"
namespace Entidades{
	namespace Obstaculos {
		Plataforma::Plataforma(sf::Vector2f size, sf::Vector2f pos)
			:Obstaculo(size, pos)
		{
			colidivel = 1;
			shape.setTexture(*pGerGraphic->getChaoTexture());
			shape.setTextureRect(sf::IntRect(192,96,96,32));
											//top, left, width, height?
			shape.setScale(1.1,1.1);
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

		void Plataforma::executar()
		{			
			

		}

	}
}