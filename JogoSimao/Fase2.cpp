#include "Fase2.h"
namespace Fases{
	Fase2::Fase2():
	GameState()
	{
		/***
		* @brief Construtor da fase 2
		* @details Inicializa a fase 2, criando as estruturas e os inimigos
		*/
		criarEstruturas();
		criarInimigos();

	}

	Fase2::~Fase2()
	{
	}

	void Fase2::executar()
	{
		/***
		* @brief Executa a fase 2
		* @details Executa a fase 2, atualizando a tela, os personagens, os obstaculos e as colis�es
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

	void Fase2::criarInimigos() {
		/***
		* @brief Inicizaliza os inimigos da fase no construtor
		* @details Cria os inimigos e adiciona na lista de personagens
		* @return void
		*/

	
	}


	void Fase2::criarEstruturas() {
		/***
		* @brief Inicizaliza as estruturas da fase no construtor
		* @details Cria as estruturas e adiciona na lista de obstaculos
		* @return void
		*/
		for (int i = 0; i <= 12; i++) {

			Entidades::Estrutura* chao1 = new Entidades::Estrutura(sf::Vector2f(100.f, 100.f), sf::Vector2f((100 * i)-700, 670),TipoEstrutura::CHAO);
			estruturas.push_back(chao1);
			listaEntidades.inserirNoFim(chao1);
			
			Entidades::Estrutura* chao2 = new Entidades::Estrutura(sf::Vector2f((100 * i)+1100, 670), TipoEstrutura::CHAO);
			estruturas.push_back(chao2);
			listaEntidades.inserirNoFim(chao2);
		}

		for (int i = 1; i <=3; i++) {

			Entidades::Estrutura* parede1 = new Entidades::Estrutura(sf::Vector2f(100.f, 100.f), sf::Vector2f(-400+(-100*i), (-330 + 670)), TipoEstrutura::PAREDE);
			estruturas.push_back(parede1);
			listaEntidades.inserirNoFim(parede1);

			Entidades::Estrutura* parede2 = new Entidades::Estrutura(sf::Vector2f(100.f, 100.f), sf::Vector2f(2000+(100*i), (-330 + 670)), TipoEstrutura::PAREDE);
			estruturas.push_back(parede2);
			listaEntidades.inserirNoFim(parede2);
			
		}		

		Entidades::Obstaculos::Plataforma* platT1 = new Entidades::Obstaculos::Plataforma( sf::Vector2f(700, 500), -4, 800, 300);
		obstaculos.push_back(platT1);
		listaEntidades.inserirNoFim(platT1);

		Entidades::Obstaculos::Plataforma* platT2 = new Entidades::Obstaculos::Plataforma( sf::Vector2f(900, 500), 4, 800, 300);
		obstaculos.push_back(platT2);
		listaEntidades.inserirNoFim(platT2);


	}
}
