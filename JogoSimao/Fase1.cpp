#include "Fase1.h"

namespace Fases{
	Fase1::Fase1() :
		Fase()
	{
		criarEstruturas();
		criaObstMedios();
		criarInimigos();		
	}

	Fase1::~Fase1()
	{
	}

	void Fase1::criarInimMedios()
	{

		for (int i = 0; i < maxInimMedios; i++) {
			Entidades::Personagens::Atirador* atirador = new Entidades::Personagens::Atirador(sf::Vector2f(2600+(i * 1000), 300), player, &projeteis, &characters);
			characters.emplace_back(atirador);
			listaEntidades.inserirNoFim(atirador);
		}
	}

	void Fase1::criaObstMedios()
	{
		for (int i = 0; i <= 5; i++) {

			Entidades::Obstaculos::Espinhos* espinho = new Entidades::Obstaculos::Espinhos(sf::Vector2f((300 * i)+400, 590));
			listaEntidades.inserirNoFim(espinho);
			obstaculos.push_back(espinho);
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
		criarInimMedios();		
	}	

	void Fase1::criarCachorro()
	{

	}

	void Fase1::criarEstruturas()
	{
		/***
		* @brief Inicizaliza as estruturas da fase no construtor
		* @details Cria as estruturas e adiciona na lista de estruturas
		* @return void
		*/
		for (int i = 0; i <= 55; i++) {			

			Entidades::Estrutura* estrutura = new Entidades::Estrutura(sf::Vector2f((100 * i)-700, 670),TipoEstrutura::CHAO);
			listaEntidades.inserirNoFim(estrutura);
			estruturas.push_back(estrutura);			
		}

		for (int i = 1; i <= 3; i++) {

			Entidades::Estrutura* parede1 = new Entidades::Estrutura(sf::Vector2f(-400 + (-100 * i), (-330 + 670)), TipoEstrutura::PAREDE);
			estruturas.push_back(parede1);
			listaEntidades.inserirNoFim(parede1);

			Entidades::Estrutura* parede2 = new Entidades::Estrutura(sf::Vector2f(4500 + (100 * i), (-330 + 670)), TipoEstrutura::PAREDE);
			estruturas.push_back(parede2);
			listaEntidades.inserirNoFim(parede2);

		}
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