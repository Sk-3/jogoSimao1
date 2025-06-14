#pragma once
#include "Fase.h"
#include "Inimigo.h"
#include "Cachorro.h"
#include "Atirador.h"
#include "Boss.h"
#include "Espinhos.h"
/**
*	Felipe Simbalista: 25/05/2025
* 
* Classe concreta Fase2
* 
*	Derivada de GameState, fase2 é responsável por instanciar entidades e aloca-los nos vetores obstaculos/characters/projeteis
* 
*	O controle dessas entidades se da pelos métodos de GameState
*/
namespace Fases{
	class Fase2 : public Fase
	{
	private:
		const int maxChefoes = 2;
	public:
		Fase2();
		~Fase2();
		void criarChefoes();
		void criarObstMedios();
		void criarProjeteis();
		void criarInimigos();
		void criarEstruturas();
		void executar();		
	};
}
