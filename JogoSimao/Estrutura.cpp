#include "Estrutura.h"

namespace Entidades {
	Entidades::Estrutura::Estrutura(sf::Vector2f pos, TipoEstrutura tipoE)
	:Entidade(pos)
	{
		tipo = tipoE;
		formatarEstrutura(tipo);			
	}

	Estrutura::Estrutura()
	{

	}

	Estrutura::~Estrutura()
	{

	}

	void Estrutura::formatarEstrutura(TipoEstrutura tipoE)
	{
		if (tipoE == TipoEstrutura::CHAO)
		{
			shape.setTexture(*pGerGraphic->getChaoTexture());
			shape.setTextureRect(sf::IntRect(192, 96, 96, 32));			
			shape.setScale(1.1, 1.1);
		}
		else
		{
			shape.setTexture(*pGerGraphic->getParedeTexture());
			shape.setTextureRect(sf::IntRect(0, 96, 96, 32));			
			shape.setScale(1.1, 1.1);
		}
	}

	void Estrutura::executar()
	{
	
	}
}
