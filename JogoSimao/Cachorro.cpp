#include "Cachorro.h"
#include <iostream>
namespace Entidades{
	namespace Personagens{
		Cachorro::Cachorro(sf::Vector2f size, sf::Vector2f pos, Character* player, std::vector<Projetil*>* projeteis, Character* dono)
			:Inimigo(size, pos, player, projeteis), pDono(dono), velocidadeCacando(6), velocidadeSeguindo(3)
		{
			/**
			*@brief Construtor da classe Cachorro
			*@detail Construtor que inicializa o tamanho, a posicao do cachorro e a cor
			*/
			shape.setFillColor(sf::Color::Blue);
			health = 1;
			mandarSeguir();
		}

		Cachorro::Cachorro()
		{
			
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
			estadoAtual->atualizar(this);


			move();
		}
	}
}