#pragma once
#include <SFML/Graphics.hpp>

/**
*	Felipe Simbalista: 25/05/2025
*
*	Classe Gerenciador Grafico
* 
*	Classe que vai definir valores padrões para a janela e para as views da aplicação
* 
*	Padrão singleton aplicado na classe para que se tenha apenas uma janela na aplicação toda
* 
*
*/
class Ente;

namespace Gerenciadores{
	class GerenciadorGrafico
	{
	private:
		float winWidth;
		float winHeight;
		sf::FloatRect standartView;
		sf::Font* font;
		sf::RenderWindow* window;
		sf::Vector2i mousePos;
	
	
		static GerenciadorGrafico* pGerGraphic;
		GerenciadorGrafico();
	
	public:
		~GerenciadorGrafico();
		//getters	
		
		const sf::FloatRect getStdView()const;
		static GerenciadorGrafico* getGerGraphic();
		sf::Vector2i* getMousePosition();
		sf::RenderWindow* getWindow();
		sf::Font* getFont();
		bool isOpen();
		//void desenharEnte(Entity* entity);
	
		void display();
		void desenharEnte(Ente* ente);
		void updateMousePosition();
		void setFrameLimit(int fps);
	};

}