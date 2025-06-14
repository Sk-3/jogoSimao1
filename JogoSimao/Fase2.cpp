#include "Fase2.h"
namespace Fases{
	Fase2::Fase2():
	Fase()
	{
		/***
		* @brief Construtor da fase 2
		* @details Inicializa a fase 2, criando as estruturas e os inimigos
		*/		
		criarEstruturas();
		criarObstMedios();
		criarInimigos();
	}

	Fase2::~Fase2()
	{
	}

	void Fase2::criarChefoes()
	{
		Entidades::Personagens::Boss* boss = new Entidades::Personagens::Boss(sf::Vector2f(2000, 300), player, &projeteis);
		characters.emplace_back(boss);
		listaEntidades.inserirNoFim(boss);	
	}

	void Fase2::criarObstMedios()
	{
		Entidades::Obstaculos::Plataforma* platT1 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(700, 600), -4, 800, 300);
		obstaculos.push_back(platT1);
		listaEntidades.inserirNoFim(platT1);

		Entidades::Obstaculos::Plataforma* platT2 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(900, 500), 4, 800, 300);
		obstaculos.push_back(platT2);
		listaEntidades.inserirNoFim(platT2);

		Entidades::Obstaculos::Plataforma* platT3 = new Entidades::Obstaculos::Plataforma(sf::Vector2f(1100, 400), -4, 800, 300);
		obstaculos.push_back(platT3);
		listaEntidades.inserirNoFim(platT3);
	}

	void Fase2::criarProjeteis()
	{
	}	

	void Fase2::criarInimigos()
	{			
		criarChefoes();	
	}


	void Fase2::criarEstruturas() {
		/***
		* @brief Inicizaliza as estruturas da fase no construtor
		* @details Cria as estruturas e adiciona na lista de estruturas
		* @return void
		*/
		for (int i = 0; i <= 12; i++) {

			Entidades::Estrutura* chao1 = new Entidades::Estrutura(sf::Vector2f((100 * i)-700, 670),TipoEstrutura::CHAO);
			estruturas.push_back(chao1);
			listaEntidades.inserirNoFim(chao1);
			
			Entidades::Estrutura* chao2 = new Entidades::Estrutura(sf::Vector2f((100 * i)+1300, 670), TipoEstrutura::CHAO);
			estruturas.push_back(chao2);
			listaEntidades.inserirNoFim(chao2);
		}

		for (int i = 1; i <=3; i++) {

			Entidades::Estrutura* parede1 = new Entidades::Estrutura(sf::Vector2f(-400+(-100*i), (-330 + 670)), TipoEstrutura::PAREDE);
			estruturas.push_back(parede1);
			listaEntidades.inserirNoFim(parede1);

			Entidades::Estrutura* parede2 = new Entidades::Estrutura(sf::Vector2f(2200+(100*i), (-330 + 670)), TipoEstrutura::PAREDE);
			estruturas.push_back(parede2);
			listaEntidades.inserirNoFim(parede2);			
		}		
	}

	void Fase2::executar()
	{
		/***
		* @brief Executa a fase 2
		* @details Executa a fase 2, atualizando a tela, os personagens, os obstaculos e as colisões
		* @return void
		*/

		window->clear();
		pGerGraphic->desenharBackground();
		pGerGraphic->setView(view);
		handleEvent();
		view.setCenter(player->getPosition());
		listaEntidades.executar();
		colision.executar();
		gravity.executar();
		listaEntidades.desenhar();
		hud.executar();
		hud.draw();
	}
}
