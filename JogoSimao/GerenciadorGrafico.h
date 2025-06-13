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
		//TEXTURA BACKGROUND
			sf::Texture background1;
			sf::Sprite backgroundSprite1;

			sf::Texture background2;
			sf::Sprite backgroundSprite2;

			sf::Texture background3;
			sf::Sprite backgroundSprite3;
		//TEXTURAS ENTIDADES
			sf::Texture projetil;
			sf::Texture chao;
			sf::Texture player;
			sf::Texture goblin;
			sf::Texture parede;

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
		//GETTERS	
			static GerenciadorGrafico* getGerGraphic();
			const sf::FloatRect getStdView();
			sf::Vector2i* getMousePosition();
			sf::Font* getFont();
			bool isOpen();
			sf::RenderWindow* getWindow();
			sf::Texture* getProjetilTexture();
			sf::Texture* getChaoTexture();
			sf::Texture* getGoblinTexture();
			sf::Texture* getPlayerTexture();
			sf::Texture* getParedeTexture();

		//SETTERS
			void setFrameLimit(int fps);
			void setView(sf::View);

		//FUNCOES
			void clear();
			void close();
			void display();
			void carregarTexturas();
			void desenharBackground();
			void desenharEnte(Ente* ente);
			void updateMousePosition();
		
	};

}