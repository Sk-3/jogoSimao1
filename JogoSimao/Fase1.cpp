#include "Fase1.h"

namespace Fases{
	Fase1::Fase1() :
		Fase() 
	{
		id = 1;
		criarCenario();
		criarPlataformas();			
		criarInimigos();
		criarObstaculo();
	}

	Fase1::~Fase1()
	{
	}

	void Fase1::criarInimMedios()
	{

		for (int i = 0; i < maxInimMedios; i++) {
			  
			listaEntidades.inserirNoFim(new Entidades::Personagens::Esqueleto(sf::Vector2f(6000 + (i * 1000), 300), &listaEntidades, player, i));
		}
	}

	void Fase1::criaObstMedios()
	{		
		
		for (int i = 0; i < 10; i++) {
 
			listaEntidades.inserirNoFim(new Entidades::Estrutura(sf::Vector2f((100 * i) + 3800, 670), TipoEstrutura::CHAO));
		}
		
		for (int i = 0; i <= 4; i++) {
			listaEntidades.inserirNoFim(new Entidades::Obstaculos::Espinho(sf::Vector2f((200 * i) + 4000, 590 - (16 * i)), 1 + (0.2 * i)));
		}
	}	

	void Fase1::criarInimigos()
	{
		/***
		* @brief Inicizaliza os inimigos da fase no construtor
		* @details Cria os inimigos e adiciona na lista de personagens e ded entidades
		* @return void
		*/
		criarInimFaceis();
		criarInimMedios();		
	}
	void Fase1::criarObstaculo()
	{
		criaObstMedios();
	}
	
	void Fase1::executar()
	{
		/**
		*@brief funcao principal da fase
		*@details Centraliza a camera no jogador e logo após gerencia os eventos de input e executa as entidades
		*	caso alguma entidade colida com a outra, o gerenciador de colisoes trata isso, e após o tratamento
		*	as entidades são desenhadas na tela
		*	no final remove os personagens e projeteis da tela
		*	caso o player morra, aciona tela de game over
		*/

		executarJanela();
		handleEvent();
		listaEntidades.executar();
		gravity.executar();
		colision.executar();
		hud.executar();
		listaEntidades.desenhar();

		hud.draw();
		if (!player->vivo())
		{
			setAction(Actions::GAME_OVER);
		}
	}

}