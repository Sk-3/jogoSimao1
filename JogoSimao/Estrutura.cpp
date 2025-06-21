#include "Estrutura.h"

namespace Entidades {
	Entidades::Estrutura::Estrutura(sf::Vector2f pos, TipoEstrutura tipoEstrutura)
	:Entidade(pos)
	{
		id = Id::Estrutura;
		tipo = tipoEstrutura;
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
			shape.setTextureRect(sf::IntRect(0, 400, 100, 300));			
			shape.setScale(1.1, 1.1);
		}
	}

	void Estrutura::executar()
	{
	
	}
	std::string Estrutura::salvar() {
		salvarEstrutura();
		return buffer.str();
	}
	void Estrutura::salvarEstrutura()
	{
		salvarEntidade();
		switch (tipo) {
		case TipoEstrutura::CHAO:{
			buffer << "CHAO";
			break;
		}
		case TipoEstrutura::PAREDE: {
			buffer << "PAREDE";
			break;
		}
		}
		std::cout << buffer.str() <<"\n";
	}
}
