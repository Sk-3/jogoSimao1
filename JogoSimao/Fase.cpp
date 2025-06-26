#include "Fase.h"
namespace Fases{

	Fase::Fase(Entidades::Personagens::Jogador* jogador1, Entidades::Personagens::Jogador* jogador2, bool carregaArquivo) :
		State(),
		player(jogador1),
		player2(jogador2),
		player2Ativo(0),
		view(pGerGraphic->getStdView())
	{
		mediador = mediadorEventos::getMediadorEventos();
		pontuacaoTotal = 0;
		id = 0;
		Entidades::Personagens::Inimigo::zerarInimigos();
		gerenciadorColisao.incluirJogador1(player);
		listaEntidades.inserirNoFim(player);
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
				player2->movimentar(Directions::LEFT);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				player2->movimentar(Directions::RIGHT);
			}
			else {
				player2->stopAxisX();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

				player2->movimentar(Directions::UP);

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				player2->movimentar(Directions::DOWN);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
				player2->dash();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				player2->atirar(&listaEntidades, &gerenciadorColisao);
			}
		}

		//Ações do jogador principal
		if(player){
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				player->movimentar(Directions::LEFT);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				player->movimentar(Directions::RIGHT);
			}
			else {
				player->stopAxisX();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				player->movimentar(Directions::UP);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				player->movimentar(Directions::DOWN);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
				player->dash();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
				player->atirar(&listaEntidades,&gerenciadorColisao);
			}
		}
		sf::Event ev;
		while (pGerGraphic->getWindow()->pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				pGerGraphic->close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::P) {
					if (!player2Ativo) {
						hud.setPlayer2(player2);
						player2Ativo = 1;
						listaEntidades.inserirNoFim(player2);
						gerenciadorColisao.incluirJogador2(player2);
					}
				}
				if (ev.key.code == sf::Keyboard::Escape) {
					mediador->notify(Actions::PAUSE);
				}
				break;
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
		pGerGraphic->clear();
		pGerGraphic->desenharBackground();
		pGerGraphic->setView(view);
		if (player2Ativo) {
			sf::Vector2f centro;
			centro.x = (player->getCenter().x + player2->getCenter().x)/ 2.f;
			centro.y = (player->getCenter().y + player2->getCenter().y)/2.f;
			view.setCenter(centro);
		}
		else {
			view.setCenter(player->getCenter());
		}
		
	}

	int Fase::getPontuacaoTotal()
	{
		return pontuacaoTotal;
	}

	void Fase::carregarSalvamento()
	{
		Entidades::Personagens::Inimigo::zerarInimigos();
		hud.setPlayer(player);
		pGerGraphic->setView(view);


		std::ifstream arquivo("save.txt");
		std::string linha;
		if (arquivo.is_open()) {
			std::getline(arquivo, linha);
			std::getline(arquivo, linha);
			std::istringstream linhaOutput(linha);
			linhaOutput >> player2Ativo;
			std::map<int, Entidades::Personagens::Cachorro*> cachorrosMap;
			std::map<int, Entidades::Personagens::Atirador*> atiradoresMap;
			std::map<int, Entidades::Personagens::Personagem*> personagensMap;
			std::vector<Entidades::Projetil*> projeteis;

			while (std::getline(arquivo, linha)) {
				
				std::istringstream linhaOutput(linha);
				//VARIAVEIS DA ENTIDADE
				std::string tipoEntidade;
				int idEntidade, ativo;
				float posicaoX, posicaoY, velocidadeX, velocidadeY;
				//VARIAVEIS PERSONAGEM
				int vida, pulos;
				//VARIAVEIS INIMIGOS
				int nivelMaldade;
				//VARIAVEL JOGADOR
				int pontuacao;
				bool jogadorDois;
				//VARIAVEL ESQUELETO
				int forca;
				//IDENTIFICADOR DONO/FILHO
				int identificadorDonoFilho;
				//VARIAVEIS PLATAFORMA
				int hmax, hmin;
				float velocidade;
				bool obstaculou;
				//VARIAVEL FOSSO
				float largura; 
				//VARIAVEL ESPINHO
				float altura;

				linhaOutput >> tipoEntidade;

				if (tipoEntidade == "JOGADOR") {
					linhaOutput >> idEntidade >> ativo >> posicaoX >> posicaoY >> velocidadeX >> velocidadeY >> vida >> pulos >> pontuacao >> jogadorDois;
					
					if(!jogadorDois){
						player->setId(idEntidade);
						player->setAtivo(ativo);
						player->setPosicao(posicaoX, posicaoY);
						player->setVelocidade(velocidadeX, velocidadeY);
						player->setVida(vida);
						player->setPulos(pulos);
						player->setPontuacao(pontuacao);
						personagensMap.emplace(idEntidade, player);
					}
					else {
						player2->setId(idEntidade);
						player2->setAtivo(ativo);
						player2->setPosicao(posicaoX, posicaoY);
						player2->setVelocidade(velocidadeX, velocidadeY);
						player2->setVida(vida);
						player2->setPulos(pulos);
						player2->setPontuacao(pontuacao);
						personagensMap.emplace(idEntidade, player2);
					}
				}
				else if (tipoEntidade == "CACHORRO") {
					linhaOutput >> idEntidade >> ativo >> posicaoX >> posicaoY >> velocidadeX >> velocidadeY >> vida >> pulos >> nivelMaldade >> identificadorDonoFilho;
					Entidades::Personagens::Cachorro* cachorro = new Entidades::Personagens::Cachorro(sf::Vector2f(posicaoX, posicaoY), player, &listaEntidades, &gerenciadorColisao);
					listaEntidades.inserirNoFim(cachorro);
					gerenciadorColisao.incluirInimigo(cachorro);
					cachorro->setId(idEntidade);
					cachorro->setAtivo(ativo);
					cachorro->setVida(vida);
					cachorro->setPulos(pulos);
					cachorro->setNivelMaldade(nivelMaldade);
					cachorro->setIdDono(identificadorDonoFilho);
					personagensMap.emplace(idEntidade, cachorro);
					cachorrosMap.emplace(idEntidade, cachorro);
				}
				else if (tipoEntidade == "ATIRADOR") {
					linhaOutput >> idEntidade >> ativo >> posicaoX >> posicaoY >> velocidadeX >> velocidadeY >> vida >> pulos >> nivelMaldade >> identificadorDonoFilho;
					Entidades::Personagens::Atirador* atirador = new Entidades::Personagens::Atirador(sf::Vector2f(posicaoX, posicaoY), player, &listaEntidades, &gerenciadorColisao);
					listaEntidades.inserirNoFim(atirador);
					gerenciadorColisao.incluirInimigo(atirador);
					atirador->setId(idEntidade);
					atirador->setAtivo(ativo);
					atirador->setVida(vida);
					atirador->setPulos(pulos);
					atirador->setNivelMaldade(nivelMaldade);
					atirador->setIdCachorro(identificadorDonoFilho);
					atiradoresMap.emplace(idEntidade, atirador);
					personagensMap.emplace(idEntidade, atirador);

				}
				else if (tipoEntidade == "ESQUELETO") {
					linhaOutput >> idEntidade >> ativo >> posicaoX >> posicaoY >> velocidadeX >> velocidadeY >> vida >> pulos >> nivelMaldade >> forca;
					Entidades::Personagens::Esqueleto* esqueleto = new Entidades::Personagens::Esqueleto(sf::Vector2f(posicaoX, posicaoY), player, &listaEntidades, &gerenciadorColisao, forca);
					listaEntidades.inserirNoFim(esqueleto);
					gerenciadorColisao.incluirInimigo(esqueleto);
					esqueleto->setId(idEntidade);
					esqueleto->setAtivo(ativo);
					esqueleto->setVida(vida);
					esqueleto->setPulos(pulos);
					esqueleto->setNivelMaldade(nivelMaldade);
					personagensMap.emplace(idEntidade, esqueleto);
				}
				else if (tipoEntidade == "PLATAFORMA") {
					linhaOutput >> idEntidade >> ativo >> posicaoX >> posicaoY >> velocidadeX >> velocidadeY >> velocidade >> hmax >> hmin >> obstaculou;
					Entidades::Obstaculos::Plataforma* plat = new Entidades::Obstaculos::Plataforma(sf::Vector2f(posicaoX, posicaoY), velocidade , hmax, hmin);
					listaEntidades.inserirNoFim(plat);
					gerenciadorColisao.incluirObstaculo(plat);
					plat->setVelocidade(velocidadeX, velocidadeY);
				}
				else if (tipoEntidade == "FOSSO") {
					linhaOutput >> idEntidade >> ativo >> posicaoX >> posicaoY >> velocidadeX >> velocidadeY >> largura>>obstaculou;
					Entidades::Obstaculos::Fosso* fosso = new Entidades::Obstaculos::Fosso(sf::Vector2f(posicaoX, posicaoY), largura);
					listaEntidades.inserirNoFim(fosso);
					gerenciadorColisao.incluirObstaculo(fosso);
					fosso->setVelocidade(velocidadeX, velocidadeY);
					fosso->setObstaculou(obstaculou);
				}
				else if (tipoEntidade == "ESPINHO") {
					linhaOutput >> idEntidade >> ativo >> posicaoX >> posicaoY >> velocidadeX >> velocidadeY >> altura;
					Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(sf::Vector2f(posicaoX, posicaoY), altura);
					listaEntidades.inserirNoFim(espinho);
					gerenciadorColisao.incluirObstaculo(espinho);
				}
				else if (tipoEntidade == "PROJETIL") {
					linhaOutput >> idEntidade >> ativo >> posicaoX >> posicaoY >> velocidadeX >> velocidadeY >> identificadorDonoFilho;
					Entidades::Projetil* projetil = new Entidades::Projetil(sf::Vector2f(posicaoX, posicaoY));
					projetil->setIdDono(identificadorDonoFilho);
					projetil->setVelocidade(velocidadeX, velocidadeY);
					projetil->setAtivo(ativo);
					listaEntidades.inserirNoFim(projetil);
					gerenciadorColisao.incluirProjetil(projetil);
					projeteis.push_back(projetil);
				}
			}

			for (auto& projet : projeteis) {
				for (auto& personagem : personagensMap) {
					if (projet->getIdDono() == personagem.first) {
						projet->setDono(personagem.second);
					}
				}
			}

			for (auto& cachorro : cachorrosMap) {
				cachorro.second->getIdDono();
				for (auto& atirador : atiradoresMap) {
					if (atirador.first == cachorro.second->getIdDono()) {
						cachorro.second->setDono(atirador.second);
					}
					if (cachorro.first == atirador.second->getIdCachorro()) {
						atirador.second->adicionarCachorro(cachorro.second);
					}
				}
			}
		}
		if (player2Ativo) {
			listaEntidades.inserirNoFim(player2);
			gerenciadorColisao.incluirJogador2(player2);
			hud.setPlayer2(player2);
		}
	}

	void Fase::carregamentoPadrao()
	{
		

		criarInimigos();
		criarObstaculo();
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
			if (!player->vivo() || !player2->vivo())
			{
				mediador->notify(Actions::GAME_OVER);
			}
			if (verificarQuantidadeInimigos() == 0) {
				mediador->notify(Actions::PASSOU_DE_FASE);
			}
		}
		if (idFase == 2) {
			if (!player->vivo() || !player2->vivo())
			{
				mediador->notify(Actions::GAME_OVER);
			}
			if (verificarQuantidadeInimigos() == 0) {
				mediador->notify(Actions::GAME_OVER);
			}
		}
	}

	void Fase::salvar() {
		std::ofstream arquivo("save.txt");
		if (arquivo.is_open()) {
			arquivo << id << std::endl;
			arquivo << player2Ativo << std::endl;
			arquivo.close();
		}
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


		if (id == 1) {
			for (int i = 0; i < 10; i++) {

				Entidades::Estrutura* estrutura = new Entidades::Estrutura(sf::Vector2f((100 * i) + 3800, 670), TipoEstrutura::CHAO);
				listaEntidades.inserirNoFim(estrutura);
				gerenciadorColisao.incluirEstrutura(estrutura);
			}
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
