#include "Cachorro.h"
#include <iostream>

namespace Entidades{
	namespace Personagens{
		Cachorro::Cachorro(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao, Personagem* dono)
			:Inimigo(pos, player, listaEntidade, gerenciadorColisao), pDono(dono), velocidadeCacando(4), velocidadeSeguindo(3), gc(gerenciadorColisao), listaEnt(listaEntidade)
		{
			/**
			*@brief Construtor da classe Cachorro
			*@detail Construtor que inicializa o tamanho, a posicao do cachorro e a cor
			*/
			health = 1;
			range = 500;
			if (dono) {
				mandarSeguir();
			}
			else {
				mandarAtacar();
			}
			arma = new Arma(this, Armas::ARMACACHORRO);
			shape.setTexture(*pGerGraphic->getCachorro());
			shape.setTextureRect(sf::IntRect(0, 0, 65, 64));
			shape.setScale(1.2, 1.2);
		}

		Cachorro::Cachorro(sf::Vector2f pos, Personagem* player, Listas::ListaEntidades* listaEntidade, Gerenciadores::GerenciadorColisao* gerenciadorColisao)
			:Inimigo(pos, player, listaEntidade, gerenciadorColisao), pDono(nullptr), velocidadeCacando(4), velocidadeSeguindo(3), gc(gerenciadorColisao), listaEnt(listaEntidade)
		{
			/**
			*@brief Construtor da classe Cachorro
			*@detail Construtor que inicializa o tamanho, a posicao do cachorro e a cor
			*/
			health = 1;
			range = 500;
			mandarAtacar();
			arma = new Arma(this, Armas::ARMACACHORRO);
			shape.setTexture(*pGerGraphic->getCachorro());
			shape.setTextureRect(sf::IntRect(0, 0, 65, 64));
			shape.setScale(1.2, 1.2);
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
				estadoAtual->sair(this);
				delete estadoAtual;
			}
			estadoAtual = novoEstado;
			if (estadoAtual) {
				estadoAtual->entrar(this);
			}
		}

		void Cachorro::mandarAtacar()
		{
			setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroAtacar()));
		}

		void Cachorro::mandarCacar()
		{
			setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroCacar()));
		}

		void Cachorro::mandarSeguir()
		{
			setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroSeguir()));
		}

		const float Cachorro::getVelocidadeSeguindo() const
		{
			return velocidadeSeguindo;
		}
		const float Cachorro::getVelocidadeCacando() const
		{
			return velocidadeCacando;
		}

		void Cachorro::executar() {
			/**
			*@brief Move o cachorro
			*@details Executa o estado atual do cachorro
			*@return void
			*/
			caiuDoMapa();

			if (!vivo()) {
				desativar();
				diminuirInimigos();
			}

			estadoAtual->atualizar(this,listaEnt, gerColisao);


			move();
		}
	}
}