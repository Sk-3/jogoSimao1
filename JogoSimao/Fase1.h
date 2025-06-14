#pragma once
#include "Fase.h"
#include "Cachorro.h"
#include "Atirador.h"
#include "Boss.h"
#include "Espinhos.h"
/**
*	Felipe Simbalista: 25/05/2025
*
*	Classe concreta Fase1
*
*	Derivada de GameState, fase1 é responsável por instanciar entidades e aloca-los nos vetores obstaculos/characters/projeteis
*
*	O controle dessas entidades se da pelos métodos de GameState
*/
namespace Fases{
	class Fase1 : public Fase
	{
	private:
		const int maxInimMedios = 2;

	public:
		Fase1();
		~Fase1();
		void criarInimMedios();
		void criaObstMedios();		
		void criarInimigos();		
		void criarCachorro();
		void criarEstruturas();
		void executar();
	};
}
