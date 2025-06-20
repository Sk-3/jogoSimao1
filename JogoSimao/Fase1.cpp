#include "Fase1.h"

namespace Fases{
	Fase1::Fase1() :
		Fase() 
	{
		id = 1;
		criarCenario();				
		criarInimigos();
		criarObstaculo();
	}

	Fase1::~Fase1()
	{
	}

	void Fase1::criarEsqueletos()
	{
		for (int i = 0; i < 3; i++) {
			
			Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(5000 + (500*i), 300), player, &listaEntidades, &gerenciadorColisao, i);
			gerenciadorColisao.incluirInimigo(esqueleto);
			listaEntidades.inserirNoFim(esqueleto);			
		}
		for (int i = 2; i < maxEsqueletos; i++) {
			if (rand() % 2) {
				
				Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(4000 + (500 * 1.5*i), 300), player, &listaEntidades, &gerenciadorColisao, i);
				gerenciadorColisao.incluirInimigo(esqueleto);
				listaEntidades.inserirNoFim(esqueleto);				
			}
		}

	}

	void Fase1::criarEspinhos()
	{		
		for (int i = 0; i < 10; i++) {

			Entidades::Estrutura* estrutura = new Entidades::Estrutura(sf::Vector2f((100 * i) + 3800, 670), TipoEstrutura::CHAO);
			listaEntidades.inserirNoFim(estrutura);
			gerenciadorColisao.incluirEstrutura(estrutura);
		}
		
		for (int i = 0; i <3; i++) {

			Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(sf::Vector2f((200 * i)+4000, 590 - (16 * i)), 1+(0.2*i));
			listaEntidades.inserirNoFim(espinho);
			gerenciadorColisao.incluirObstaculo(espinho);
		}

		for (int i = 0; i < 3; i++) {
			if (rand() % 2) {
				Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(sf::Vector2f((200 * i) + 4600, 590 - (16 * i)), 1 + (0.2 * i));
				listaEntidades.inserirNoFim(espinho);
				gerenciadorColisao.incluirObstaculo(espinho);
			}
		}
	}	

	void Fase1::criarInimigos()
	{
		/***
		* @brief Inicizaliza os inimigos da fase no construtor
		* @details Cria os inimigos e adiciona na lista de personagens e ded entidades
		* @return void
		*/
		criarCachorro();
		criarEsqueletos();		
	}
	void Fase1::criarObstaculo()
	{
		criarEspinhos();
		criarPlataformas();
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
		aplicarGravidade();
		gerenciadorColisao.executar();
		hud.executar();
		listaEntidades.desenhar();
		hud.draw();

		if (!player->vivo())
		{
			setAction(Actions::GAME_OVER);
		}
	}

}