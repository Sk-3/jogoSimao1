#pragma once
#include "Fase.h"
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
		const int maxAtiradores = 4;
	public:
		Fase2(Entidades::Personagens::Jogador* jg1, Entidades::Personagens::Jogador* jg2, bool carregaArquivo);
		~Fase2();
		void criarAtiradores();		
		void criarFosso();
		void criarProjeteis();
		void criarInimigos();
		void criarObstaculo();
		void executar();		

	};
}
