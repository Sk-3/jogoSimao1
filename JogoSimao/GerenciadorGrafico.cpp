#include "GerenciadorGrafico.h"
#include <iostream>
#include "Ente.h"
namespace Gerenciadores {
	GerenciadorGrafico* GerenciadorGrafico::pGerGraphic = NULL;
	GerenciadorGrafico::GerenciadorGrafico()
		:winWidth(1280.f),
		winHeight(720.f),
		standartView(sf::FloatRect(0.f, 0.f,winWidth, winHeight))
	{
		/**
		* @brief Construtor da classe GerenciadorGrafico, inicializa a janela e carrega a fonte.
		* @param winWidth Largura da janela.
		* @param winHeight Altura da janela.
		*/

		window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "Jogo Simao", sf::Style::Close | sf::Style::Titlebar);
		font = new sf::Font();
		carregarTexturas();

	}

	GerenciadorGrafico::~GerenciadorGrafico()
	{
		/**
		* @brief Destrutor da classe GerenciadorGrafico, libera os recursos utilizados pela janela e pela fonte.
		*/
		if (window)
			delete window;
		if(font)
			delete font;
	}

	void GerenciadorGrafico::display() {
		/**
		* @brief Exibe o conteúdo da janela.
		* @return void
		*/
		window->display();
	}
	void GerenciadorGrafico::carregarTexturas()
	{
		if (!font->loadFromFile("..//JogoSimao//TypeLightSans-KV84p.otf")) {
			std::cerr << "Erro ao carregar a fonte";
		}
		if (!background1.loadFromFile(("..//background//background_layer_1.PNG"))) {
			std::cout << "Falha ao carregar textura Background_layer_1";
		}
		backgroundSprite1.setTexture(background1);
		backgroundSprite1.setScale(4, 4);

		if (!background2.loadFromFile(("..//background//background_layer_2.PNG"))) {
			std::cout << "Falha ao carregar textura Background_layer_2";
		}
		backgroundSprite2.setTexture(background2);
		backgroundSprite2.setScale(4, 4);

		if (!background3.loadFromFile(("..//background//background_layer_3.PNG"))) {
			std::cout << "Falha ao carregar textura Background_layer_3";
		}
		backgroundSprite3.setTexture(background3);
		backgroundSprite3.setScale(4, 4);


		if (!projetil.loadFromFile("..//textures//orb.PNG")) {
			std::cout << "Falha ao carregar textura orb";
		}

		if (!chao.loadFromFile("..//textures//tileset_32x32.PNG")) {
			std::cout << "Falha ao carregar textura tileset_32x32.PNG";
		}

		if (!player.loadFromFile("..//textures//AIM.PNG")) {
			std::cout << "Falha ao carregar textura Aim.PNG";
		}
		sf::Image playerInvertido;
		if (!playerInvertido.loadFromFile("..//textures//AIM.PNG")) {
			std::cout << "Falha ao carregar textura Aim.PNG";
		}
		else {
			playerInvertido.flipHorizontally();
			playerLeft.loadFromImage(playerInvertido);
		}
		

		if (!goblin.loadFromFile("..//textures//goblin.PNG")) {
			std::cout << "Falha ao carregar textura goblin.PNG";
		}

		if (!parede.loadFromFile("..//textures//arvore.PNG")) {
			std::cout << "Falha ao carregar textura arvore.PNG";
		}

		if (!boss.loadFromFile("..//textures//boss.PNG")) {
			std::cout << "Falha ao carregar textura arvore.PNG";
		}

		if (!cachorro.loadFromFile("..//textures//cachorro.PNG")) {
			std::cout << "Falha ao carregar textura arvore.PNG";
		}

		if (!espinho.loadFromFile("..//textures//espinhos.PNG")) {
			std::cout << "Falha ao carregar textura espinhos.PNG";
		}

	}
	void GerenciadorGrafico::desenharBackground()
	{
		window->draw(backgroundSprite1);
		window->draw(backgroundSprite2);
		window->draw(backgroundSprite3);
	}
	void GerenciadorGrafico::desenharEnte(Ente* ente)
	{
		/**
		*@brief Desenha a figura do ente
		*@param ente figura que será desenhada
		*/

		window->draw(*ente->getFigura());

	}
	bool GerenciadorGrafico::isOpen()
	{
		/**
		* @brief Verifica se a janela está aberta.
		* @return 1 se a janela estiver aberta, 0 caso contrário.
		*/
		return window->isOpen();
	}

	sf::RenderWindow* GerenciadorGrafico::getWindow()
	{
		return window;
	}

	sf::Texture* GerenciadorGrafico::getProjetilTexture() {
		return &projetil; 
	}

	sf::Texture* GerenciadorGrafico::getChaoTexture()
	{
		return &chao;
	}

	sf::Texture* GerenciadorGrafico::getGoblinTexture()
	{
		return &goblin;
	}

	sf::Texture* GerenciadorGrafico::getPlayerTexture() {
		return &player;
	}
	sf::Texture* GerenciadorGrafico::getParedeTexture()
	{
		return &parede;
	}
	sf::Texture* GerenciadorGrafico::getPlayerInvertido()
	{
		return &playerLeft;
	}
	sf::Texture* GerenciadorGrafico::getBoss()
	{
		return &boss;
	}
	sf::Texture* GerenciadorGrafico::getCachorro()
	{
		return &cachorro;
	}
	sf::Texture* GerenciadorGrafico::getEspinho()
	{
		return &espinho;
	}


	void GerenciadorGrafico::clear() {
		window->clear();
	}

	const sf::FloatRect GerenciadorGrafico::getStdView()
	{
		return standartView;
	}

	GerenciadorGrafico* GerenciadorGrafico::getGerGraphic()
	{
		if (!pGerGraphic) {
			pGerGraphic = new GerenciadorGrafico();
		}
		return pGerGraphic;
	}
	sf::Vector2i* GerenciadorGrafico::getMousePosition()
	{
		/**
		* @brief Retorna a posição atual do mouse na janela.
		* @return Um ponteiro para um objeto sf::Vector2i que contém as coordenadas do mouse.
		*/
		return &mousePos;
	}
	sf::Font* GerenciadorGrafico::getFont()
	{
		/**
		* @brief Retorna um ponteiro para a fonte utilizada na renderização de texto.
		* @return Um ponteiro para um objeto sf::Font que representa a fonte.
		*/
		return font;
	}

	void GerenciadorGrafico::updateMousePosition()

	{
		/**
		*@brief Atualiza a posição do mouse na janela.
		*@return void 
		*/

		mousePos = sf::Mouse::getPosition(*window);
	
	}

	void GerenciadorGrafico::setFrameLimit(int fps)
	{
		/**
		* @brief Define o limite de quadros por segundo (FPS) para a janela.
		* @param fps O número máximo de quadros por segundo que a janela deve renderizar.
		* @return void
		*/
		window->setFramerateLimit(fps);
	}

	void GerenciadorGrafico::close() {
		window->close();
	}

	void GerenciadorGrafico::setView(sf::View view)
	{
		window->setView(view);
	}

}