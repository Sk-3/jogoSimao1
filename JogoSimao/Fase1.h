#pragma once
#include "Fase.h"
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
		const int maxEsqueletos = 4;

	public:
		
		Fase1(Entidades::Personagens::Jogador* jg1, Entidades::Personagens::Jogador* jg2, bool carregaArquivo);
		~Fase1();

		void criarEsqueletos();
		void criarEspinhos();		
		void criarInimigos();		
		void criarObstaculo();		
		void executar();
	};
}
