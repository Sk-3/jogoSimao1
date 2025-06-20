#include "Fase2.h"
namespace Fases{
	Fase2::Fase2(Entidades::Personagens::Jogador* jg1, Entidades::Personagens::Jogador* jg2):
	Fase(jg1,jg2)
	{
		
		jg1->posicionarNoInicio();
		jg2->posicionarNoInicio();
		criarCenario();
		criarPlataformas();		
		criarInimigos();
		criarObstaculo();
	}

	Fase2::~Fase2()
	{
	}

	void Fase2::criarAtiradores()
	{
		for (int i = 0; i < 3; i++) {
			Entidades::Personagens::Atirador* atirador = new Entidades::Personagens::Atirador(sf::Vector2f(5000 + (i * 500), 300), player, &listaEntidades, &gerenciadorColisao);
			gerenciadorColisao.incluirInimigo(atirador);
			listaEntidades.inserirNoFim(atirador);
			criarCachorro(atirador);
		}

		for (int i = 3; i < maxAtiradores; i++) {
			if (rand() % 2) {
				Entidades::Personagens::Atirador* atirador = new Entidades::Personagens::Atirador(sf::Vector2f(5000 + (i * 500), 300), player, &listaEntidades, &gerenciadorColisao);
				gerenciadorColisao.incluirInimigo(atirador);
				listaEntidades.inserirNoFim(atirador);
				criarCachorro(atirador);
			}
		}
		
	}
	

	void Fase2::criarObstDificil()
	{
		for (int i = 0; i < 3; i++) {

			Entidades::Obstaculos::Fosso* fosso = new Entidades::Obstaculos::Fosso(sf::Vector2f(4000+(200*i), 670), 1);
			gerenciadorColisao.incluirObstaculo(fosso);
			listaEntidades.inserirNoFim(fosso);
		}
	}

	void Fase2::criarProjeteis()
	{
	}	

	void Fase2::criarInimigos()
	{			
		criarCachorro();
		criarAtiradores();	
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
		aplicarGravidade();
		gerenciadorColisao.executar();

		hud.executar();
		listaEntidades.desenhar();

		hud.draw();
		
		if (!player->vivo())
		{
			setAction(Actions::GAME_OVER);
		}
		if (verificarQuantidadeInimigos() == 0) {
			setAction(Actions::GAME_OVER);
		}
	}
}
