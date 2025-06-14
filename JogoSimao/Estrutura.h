#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include "TipoEstrutura.h"

/**
*	Ramon Vargas: 12/06/2025
*
*	Classe concreta Estrutura
*
*	Representa os objetos estruturais do jogo, como chão e paredes
*/

namespace Entidades {
	class Estrutura: public Entidade
	{
	private:
		TipoEstrutura tipo;

	public:
		Estrutura(sf::Vector2f pos, TipoEstrutura tipoE);
		Estrutura();
		~Estrutura();
		void formatarEstrutura(TipoEstrutura tipoE);
		void executar();
	};
}