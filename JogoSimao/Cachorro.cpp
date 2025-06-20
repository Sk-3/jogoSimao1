#include "Cachorro.h"
#include <iostream>

namespace Entidades{
	namespace Personagens{
		Cachorro::Cachorro(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao, Personagem* dono)
			:Inimigo(pos, player, listaEntidade, gerenciadorColisao), pDono(dono), velocidade(3), gc(gerenciadorColisao), listaEnt(listaEntidade)
		{
			health = 1;
			range = 500;
			nivel_maldade = 1 + (rand() % 10);
			moveSpeed = velocidade;
			if (dono) {
				mandarSeguir();
			}
			else {
				mandarAtacar();
			}
			arma = new Arma(this, Armas::ARMACACHORRO);
			shape.setTexture(*pGerGraphic->getCachorro());
			shape.setTextureRect(sf::IntRect(0, 0, 65, 64));
			shape.setScale(1 + (float)nivel_maldade / 10, 1 + (float)nivel_maldade / 10);
		}

		Cachorro::Cachorro(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao)
			:Inimigo(pos, player, listaEntidade, gerenciadorColisao), pDono(nullptr), velocidade(3), gc(gerenciadorColisao), listaEnt(listaEntidade)
		{
			/**
			*@brief Construtor da classe Cachorro
			*@detail Construtor que inicializa o tamanho, a posicao do cachorro e a cor
			*/
			health = 1;
			range = 500;
			nivel_maldade = 1 + (rand() % 10);
			moveSpeed = velocidade;
			mandarAtacar();
			arma = new Arma(this, Armas::ARMACACHORRO);
			shape.setTexture(*pGerGraphic->getCachorro());
			shape.setTextureRect(sf::IntRect(0, 0, 65, 64));
			shape.setScale(1 + (float)nivel_maldade / 10, 1 + (float)nivel_maldade / 10);
		}


		Cachorro::~Cachorro()
		{
		}		

		void Cachorro::seguirDono()
		{
			if (getPosition().x - pDono->getPosition().x < 0) {
				speed.x = moveSpeed;
				direction = Directions::RIGHT;
			}
			else {
				speed.x = -moveSpeed;
				direction = Directions::LEFT;
			}

		}

		void Cachorro::setEstado(EstadoCachorro* novoEstado)
		{
			if (estadoAtual) {
				 delete estadoAtual;
			}			
			estadoAtual = novoEstado;			
		}

		void Cachorro::setRange(float range)
		{
			this->range = range;
		}

		void Cachorro::mandarAtacar()
		{
			if (estadoAtual) {
				if (estadoAtual->getId() != 1) {
					setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroAtacar()));
				}
			}
			else
			{
				setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroAtacar()));
			}
		}

		void Cachorro::mandarSeguir()
		{
			if (estadoAtual) {
				if (estadoAtual->getId() != 2) {
					setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroSeguir()));
				}
			}
			else
			{
				setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroSeguir()));
			}
		}

		void Cachorro::mandarCacar()
		{
			if (estadoAtual) {
				if (estadoAtual->getId() != 3) {
					setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroCacar()));
				}
			}
			else
			{
				setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroCacar()));
			}
		}	
			

		void Cachorro::executar() {
			/**
			*@brief Move o cachorro
			*@details Executa o estado atual do cachorro
			*@return void
			*/
			

			if (!vivo()) {
				desativar();
			}

			estadoAtual->atualizar(this,listaEnt, gerColisao);


			move();
		}
	}
}