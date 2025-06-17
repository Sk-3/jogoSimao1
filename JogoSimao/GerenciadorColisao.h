#pragma once
#include "Jogador.h"
#include "Estrutura.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "vector"

/**
*	Felipe Simbalista: 25/05/2025
* 
*	Faz a verificação de colisão
* 
*	Se uma entidade entra dentro de outra, essa classe é responsável por chamar uma ação da entidade que se locomoveu pra dentro da outra
* 
*	Essa classe não altera diretamente outras, ela apenas "avisa" outras classes o que está acontecendo
*/

namespace Gerenciadores{
	class GerenciadorColisao
	{
	private:
		std::vector<Entidades::Personagens::Personagem*>* characters;
		std::vector<Entidades::Obstaculos::Obstaculo*>* obstaculos;
		std::vector<Entidades::Projetil*>* projeteis;
		std::vector<Entidades::Estrutura*>* estruturas;
	public:

		void executar();
		GerenciadorColisao();
		GerenciadorColisao(std::vector<Entidades::Personagens::Personagem*>* characters, std::vector<Entidades::Obstaculos::Obstaculo*>*, std::vector<Entidades::Projetil*>* projeteis, std::vector<Entidades::Estrutura*>* estruturas);
		~GerenciadorColisao();
	
	
		const bool verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2);
		void tratarColisaoProjeteis();
		void tratarColisaoPersonagens();
		void empurrarPersonagem(Entidades::Personagens::Personagem* personagem, Entidades::Entidade* entidade);
		void colision();
	
	};

}