#include "Hud.h"


Hud::Hud()
{
	/**
	*@brief Construtor da classe Hud, inicializa o objeto hud 
	*@return void
	*/
	player = nullptr;
	hud.setFont(*(pGerGraphic->getFont()));
	hud.setCharacterSize(30);
}

Hud::~Hud()
{
}

void Hud::setPlayer(Entidades::Personagens::Player* player)
{
	/**
	*@brief Associa o player que sera utilizado no hud
	*@param player Ponteiro para o objeto Player que sera utilizado no hud
	*@return void
	*/
	this->player = player;
}

void Hud::draw()
{
	/**
	*@brief Desenha o hud na tela
	*@details Reinicia a janela para a view original para que a hud fique fixa no topo da tela
	*		  apos isso, desenha o hud na tela com as informacoes do jogador
	*@return void
	*/
	sf::RenderWindow* window = pGerGraphic->getWindow();
	window->setView(window->getDefaultView());
	window->draw(hud);
}

void Hud::executar()
{
	/**
	*@brief Executa a Hud
	*@details Atualiza o hud com o tempo de jogo, vida do jogador e pontos
	*@return void
	*/
	std::stringstream ss;
	ss <<"Tempo: "<< hudClock.getElapsedTime().asSeconds() << "\nVida:"<< player->getHealth() << "\nPontos : 0";
	hud.setString(ss.str());

}
