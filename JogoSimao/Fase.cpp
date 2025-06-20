#include "Fase.h"
namespace Fases{

	Fase::Fase(Entidades::Personagens::Jogador* jogador1, Entidades::Personagens::Jogador* jogador2) :
		State(),
		player(jogador1),
		player2(jogador2),
		player2Ativo(0),
		view(pGerGraphic->getStdView())
	{
		gerenciadorColisao.incluirJogador1(player);
		listaEntidades.inserirNoFim(player);
		id = 0;
		hud.setPlayer(player);
		pGerGraphic->setView(view);
		
	}

	

	Fase::~Fase() {
		listaEntidades.desalocar();
	}

	void Fase::handleEvent()
	{
		/**
		* @brief Gerencia os eventos de teclado
		* @details Verifica as teclas pressionadas e executa as ações correspondentes para o jogador e o jogador 2 (se existir).
		* @return void
		*/
		//Ações do jogador secundario
		if (player2Ativo) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				player2->moveLeft();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				player2->moveRight();
			}
			else {
				player2->stopAxisX();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

				player2->moveUp();

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				player2->moveDown();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
				player2->dash();
			}
		}

		//Ações do jogador principal
		if(player){
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				player->moveLeft();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				player->moveRight();
			}
			else {
				player->stopAxisX();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				player->moveUp();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				player->moveDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
				player->dash();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				player->atirar(&listaEntidades,&gerenciadorColisao);
			}
		}
		sf::Event ev;
		while (window->pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				pGerGraphic->close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::P) {
					if (!player2Ativo) {
						player2Ativo = 1;
						listaEntidades.inserirNoFim(player2);
						gerenciadorColisao.incluirJogador2(player2);
					}
				}
				if (ev.key.code == sf::Keyboard::Escape) {
					setAction(Actions::PAUSE);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (ev.mouseButton.button == sf::Mouse::Left) {
					//mouseClick();
				}
			}
		}
	}

	void Fase::executarJanela()
	{
		/**
		* @brief Executa a janela
		* @details Limpa a janela, define a view e atualiza o centro da view com a posição do jogador.
		* @return void
		*/
		window->clear();
		pGerGraphic->desenharBackground();
		pGerGraphic->setView(view);
		view.setCenter(player->getPosition());
	}

	void Fase::criarCachorro(Entidades::Personagens::Atirador* dono) {
		if(dono){
			Entidades::Personagens::Cachorro* cachorro = new Entidades::Personagens::Cachorro(sf::Vector2f(dono->getPosition().x + rand() % 300, dono->getPosition().y + (rand() % 300)), player, &listaEntidades, &gerenciadorColisao, dono);
			listaEntidades.inserirNoFim(cachorro);
			gerenciadorColisao.incluirInimigo(cachorro);
			dono->adicionarCachorro(cachorro);
		}
	}
	void Fase::criarCachorro()
	{
		for (int i = 0; i < 3; i++) {
			Entidades::Personagens::Cachorro* cachorro = new Entidades::Personagens::Cachorro(sf::Vector2f(2500 + (250*i), 300), player, &listaEntidades, &gerenciadorColisao);
			listaEntidades.inserirNoFim(cachorro);
			gerenciadorColisao.incluirInimigo(cachorro);
		}
		if (rand() % 2) {
			Entidades::Personagens::Cachorro* cachorro = new Entidades::Personagens::Cachorro(sf::Vector2f(3500, 300), player, &listaEntidades, &gerenciadorColisao);
			listaEntidades.inserirNoFim(cachorro);
			gerenciadorColisao.incluirInimigo(cachorro);
		}
		

	}

	void Fase::criarPlataformas()
	{
		int sentido = -1;
		if (rand() % 2) {
			for (int i = 0; i < 4; i++) {
				Entidades::Obstaculos::Plataforma* plat = new Entidades::Obstaculos::Plataforma(sf::Vector2f(900+(200*i), 600), (3 + id) * sentido, 800, 300);
				listaEntidades.inserirNoFim(plat);
				gerenciadorColisao.incluirObstaculo(plat);
				sentido *= -1;
			}			
		}
		else {
			for (int i = 0; i < 3; i++) {
				Entidades::Obstaculos::Plataforma* plat = new Entidades::Obstaculos::Plataforma(sf::Vector2f(900 + (300 * i), 600), (3 + id) * sentido, 800, 300);
				listaEntidades.inserirNoFim(plat);
				gerenciadorColisao.incluirObstaculo(plat);
				sentido *= -1;
			}
		}		
	}

	void Fase::controladorEstado(int idFase)
	{
		if(idFase == 1){
			if (!player->vivo())
			{
				setAction(Actions::GAME_OVER);
			}
			if (verificarQuantidadeInimigos() == 0) {
				setAction(Actions::PASSOU_DE_FASE);
			}
			if (getAction() == Actions::SALVAR) {
				listaEntidades.salvar();
				setAction(Actions::PAUSE);
			}
		}
		if (idFase == 2) {
			if (!player->vivo())
			{
				setAction(Actions::GAME_OVER);
			}
			if (verificarQuantidadeInimigos() == 0) {
				setAction(Actions::GAME_OVER);
			}
			if (getAction() == Actions::SALVAR) {
				listaEntidades.salvar();
				setAction(Actions::PAUSE);
			}
		}
	}

	void Fase::salvar() {
		listaEntidades.salvar();
	}
	void Fase::criarCenario()
	{
		for (int i = 0; i < 15; i++) {

			Entidades::Estrutura* estrutura = new Entidades::Estrutura(sf::Vector2f((100 * i) - 700, 670), TipoEstrutura::CHAO);
			listaEntidades.inserirNoFim(estrutura);
			gerenciadorColisao.incluirEstrutura(estrutura);
		}

		Entidades::Estrutura* parada = new Entidades::Estrutura(sf::Vector2f(1800, 638), TipoEstrutura::CHAO);
		listaEntidades.inserirNoFim(parada);
		gerenciadorColisao.incluirEstrutura(parada);

		for (int i = 0; i < 20; i++) {

			Entidades::Estrutura* estrutura = new Entidades::Estrutura(sf::Vector2f((100 * i) +1800, 670), TipoEstrutura::CHAO);
			listaEntidades.inserirNoFim(estrutura);
			gerenciadorColisao.incluirEstrutura(estrutura);
		}

		for (int i = 0; i < 30; i++) {

			Entidades::Estrutura* estrutura = new Entidades::Estrutura(sf::Vector2f((100 * i) + 4800, 670), TipoEstrutura::CHAO);
			listaEntidades.inserirNoFim(estrutura);
			gerenciadorColisao.incluirEstrutura(estrutura);
		}

		for (int i = 0; i < 3; i++) {

			Entidades::Estrutura* parede1 = new Entidades::Estrutura(sf::Vector2f(-400 + (-100 * i), (-330 + 670)), TipoEstrutura::PAREDE);
			
			listaEntidades.inserirNoFim(parede1);
			gerenciadorColisao.incluirEstrutura(parede1);

			Entidades::Estrutura* parede2 = new Entidades::Estrutura(sf::Vector2f(7500 + (100 * i), (-330 + 670)), TipoEstrutura::PAREDE);
			listaEntidades.inserirNoFim(parede2);
			gerenciadorColisao.incluirEstrutura(parede2);
		}
	}

	void Fase::aplicarGravidade()
	{
		for (Lista<Entidades::Entidade*>::Iterator it = listaEntidades.inicio(); it != listaEntidades.fim(); ++it) {
			(*it)->changeSpeed(sf::Vector2f(0, 0.2));
		}
	}

	int Fase::verificarQuantidadeInimigos()
	{
		return Entidades::Personagens::Inimigo::getQuantidadeInimigos();
	}
}
