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
		window = new sf::RenderWindow(sf::VideoMode(winWidth, winHeight), "Menu Teste", sf::Style::Close | sf::Style::Titlebar);
		font = new sf::Font();
		if (!font->loadFromFile("C://Users//Felipe//Documents//menuTeste//menuTeste//TypeLightSans-KV84p.otf")) {
			std::cerr << "Erro ao carregar a fonte";
		}
	}

	GerenciadorGrafico::~GerenciadorGrafico()
	{
		if (window)
			delete window;
		if(font)
			delete font;
	}

	void GerenciadorGrafico::display() {
		window->display();
	}
	bool GerenciadorGrafico::isOpen()
	{
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
		return &mousePos;
	}
	sf::RenderWindow* GerenciadorGrafico::getWindow(){
		return window;
	}
	sf::Font* GerenciadorGrafico::getFont()
	{
		return font;
	}

	void GerenciadorGrafico::updateMousePosition()
	{
		mousePos = sf::Mouse::getPosition(*window);
	
	}

	void GerenciadorGrafico::setFrameLimit(int fps)
	{
		window->setFramerateLimit(fps);
	}

}