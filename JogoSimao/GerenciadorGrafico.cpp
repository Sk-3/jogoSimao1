#include "GerenciadorGrafico.h"
#include <iostream>
#include "Entity.h"
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

		window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "Menu Teste", sf::Style::Close | sf::Style::Titlebar);
		font = new sf::Font();
		if (!font->loadFromFile("C://Users//Felipe//Documents//menuTeste//menuTeste//TypeLightSans-KV84p.otf")) {
			std::cerr << "Erro ao carregar a fonte";
		}
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
	bool GerenciadorGrafico::isOpen()
	{
		/**
		* @brief Verifica se a janela está aberta.
		* @return 1 se a janela estiver aberta, 0 caso contrário.
		*/
		return window->isOpen();
	}

	//void GerenciadorGrafico::desenharEnte(Entity* entity)
	//{
	//	window->draw(entity->getShape());
	//}

	const sf::FloatRect GerenciadorGrafico::getStdView() const
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
	sf::RenderWindow* GerenciadorGrafico::getWindow(){
		/**
		* @brief Retorna um ponteiro para a janela de renderização.
		* @return Um ponteiro para um objeto sf::RenderWindow que representa a janela de renderização.
		*/
		return window;
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
		window->setFramerateLimit(fps);
	}

}