#include "Fase2.h"
namespace Fases{
	Fase2::Fase2():
		Fase()
	{
		id = 2;
		criarCenario();


		criarPlataformas();		
		criarInimigos();
		criarObstaculo();
	}

	Fase2::~Fase2()
	{
		 
	}

	void Fase2::criarChefoes()
	{
		for (int i = 0; i < maxChefoes; i++) {
			listaEntidades.inserirNoFim(new Entidades::Personagens::Atirador(sf::Vector2f(6000 + (i * 1000), 300), &listaEntidades, player));
		}
	}
	

	void Fase2::criarObstDificil()
	{
		for (int i = 0; i < 3; i++) {

			  
			listaEntidades.inserirNoFim(new Entidades::Obstaculos::Fosso(sf::Vector2f(4000 + (200 * i), 670), 1));
		}
	}

	void Fase2::criarProjeteis()
	{
	}	

	void Fase2::criarInimigos()
	{			
		criarInimFaceis();
		criarChefoes();	
	}
	void Fase2::criarObstaculo()
	{
		criarObstDificil();
	}

	void Fase2::executar()
	{
		/***
		* @brief Executa a fase 2
		* @details Executa a fase 2, atualizando a tela, os personagens, os obstaculos e as colisões
		* @return void
		*/

		executarJanela();
		handleEvent();
		listaEntidades.executar();
		gravity.executar();
		GC.executar();
		hud.executar();
		listaEntidades.desenhar();
		hud.draw();
		if (!player->vivo())
		{
			setAction(Actions::GAME_OVER);
		}
		
	}
}
