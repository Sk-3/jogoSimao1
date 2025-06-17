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
			Entidades::Personagens::Atirador* atirador = new Entidades::Personagens::Atirador(sf::Vector2f(6000 + (i * 1000), 300), player, &projeteis, &characters);
			characters.emplace_back(atirador);
			listaEntidades.inserirNoFim(atirador);
		}
	}
	

	void Fase2::criarObstDificil()
	{
		for (int i = 0; i < 3; i++) {

			Entidades::Obstaculos::Fosso* fosso = new Entidades::Obstaculos::Fosso(sf::Vector2f(4000+(200*i), 670), 1);
			obstaculos.push_back(fosso);
			listaEntidades.inserirNoFim(fosso);
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
		for (auto const& obst : obstaculos) {
			obst->executar();
		}
		for (auto const& charact : characters) {
			charact->executar();
		}
		for (auto const& projetil : projeteis) {
			projetil->executar();
		}
		gravity.executar();
		colision.executar();

		hud.executar();

		for (auto const& charact : characters) {
			charact->desenhar();
		}
		for (auto const& projetil : projeteis) {
			projetil->desenhar();
		}
		for (auto const& obst : obstaculos) {
			obst->desenhar();
		}

		for (auto const& estrut : estruturas) {
			estrut->desenhar();
		}

		hud.draw();
		removerProjeteis();
		if (!player->vivo())
		{
			setAction(Actions::GAME_OVER);
		}
		removerPersonagens();
	}
}
