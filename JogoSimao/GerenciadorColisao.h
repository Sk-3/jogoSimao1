#pragma once
#include "Player.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "vector"
#include "Ente.h"

/**
*	Felipe Simbalista: 25/05/2025
* 
*	Faz a verifica��o de colis�o
* 
*	Se uma entidade entra dentro de outra, essa classe � respons�vel por chamar uma a��o da entidade que se locomoveu pra dentro da outra
* 
*	Essa classe n�o altera diretamente outras, ela apenas "avisa" outras classes o que est� acontecendo
*/

namespace Gerenciadores{
	class GerenciadorColisao : public Ente
	{
	private:
		std::vector<Entidades::Personagens::Character*>* characters;
		std::vector<Entidades::Obstaculos::Obstaculo*>* obstaculos;
		std::vector<Entidades::Projetil*>* projeteis;
	public:

		void executar();
		GerenciadorColisao();
		GerenciadorColisao(std::vector<Entidades::Personagens::Character*>* characters, std::vector<Entidades::Obstaculos::Obstaculo*>*, std::vector<Entidades::Projetil*>* projeteis);
		~GerenciadorColisao();
	
	
		void colision();
	
	};

}