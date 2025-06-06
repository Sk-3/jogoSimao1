#pragma once
#include "GameState.h"
#include "Cachorro.h"
#include "Atirador.h"
#include "Boss.h"
#include "Espinhos.h"
/**
*	Felipe Simbalista: 25/05/2025
*
* Classe concreta Fase2
*
*	Derivada de GameState, fase2 � respons�vel por instanciar entidades e aloca-los nos vetores obstaculos/characters/projeteis
*
*	O controle dessas entidades se da pelos m�todos de GameState
*/
namespace Fases{
	class Fase1 : public GameState
	{
	private:
	public:
		Fase1();
		~Fase1();
		void executar();
		void criarInimigos();
		void criarEstruturas();
	};
}
