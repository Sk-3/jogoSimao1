#include "Entidade.h"
#include <iostream>

int Entidades::Entidade::contadorEntidades = 0;
namespace Entidades{

	Entidade::Entidade() :
		position(sf::Vector2f(0.f, 0.f)), buffer()
	{
		idUnico = contadorEntidades++;
		ativo = 1; 
		shape.scale(3, 3);
		shape.setPosition(position);
		shape.setTexture(*pGerGraphic->getProjetilTexture());
		setFigura(&shape);
	}

	Entidade::Entidade(sf::Vector2f pos) :
		position(pos), buffer()
	{

		/***
		* @brief construtor da classe Entity, inicializa o corpo do objeto com a posicao e tamanho especificados
		* @param pos - posicao do corpo do objeto
		*/

		idUnico = contadorEntidades++;
		ativo = 1;
		shape.scale(3, 3);
		shape.setPosition(pos);
		shape.setTexture(*pGerGraphic->getProjetilTexture());
		setFigura(&shape);
	}

	Entidade::~Entidade()
	{
	}


	const sf::Vector2f Entidade::getCenter()
	{
		sf::Vector2f center;

		center.x = shape.getGlobalBounds().left + shape.getGlobalBounds().width / 2.f;

		center.y = shape.getGlobalBounds().top + shape.getGlobalBounds().height / 2.f;

		return center;
	}
	const sf::Vector2f Entidade::getPosition()
	{
		/***
		* @brief retorna a posicao do corpo do objeto
		* @return sf::Vector2f - posicao do corpo do objeto
		*/
		return shape.getPosition();
	}
	const int Entidade::getIdUnico() const
	{
		return idUnico;
	}
	const sf::FloatRect Entidade::getBounds()
	{
		/***
		* @brief retorna o retangulo delimitador do corpo do objeto
		* @return sf::FloatRect - retangulo delimitador do corpo do objeto
		*/
		return shape.getGlobalBounds();
	}

	void Entidade::move()
	{
		/***
		* @brief move o corpo do objeto na direcao do vetor speed
		*/
		shape.move(speed);		
	}
	void Entidade::changeSpeed(sf::Vector2f addSpeed)
	{
		/***
		* @brief altera a velocidade do corpo do objeto
		* @param addSpeed - vetor que sera adicionado a velocidade atual do corpo do objeto
		*/
		speed += addSpeed;
	}

	void Entidade::salvarEntidade()
	{
		std::stringstream novoBuffer;
		buffer.str("");
		buffer.clear();
		switch (getId()) {
			case Id::Jogador: {
				buffer << "JOGADOR" << " ";
				break;
			}
			case Id::Atirador:{
				buffer << "ATIRADOR" << " ";
				break;
			}
			case Id::Cachorro: {
				buffer << "CACHORRO" << " ";
				break;
			}
			case Id::Espinho: {
				buffer << "ESPINHO" << " ";
				break;
			}
			case Id::Esqueleto: {
				buffer << "ESQUELETO" << " ";
				break;
			}
			case Id::Fosso: {
				buffer << "FOSSO" << " ";
				break;
			}
			case Id::Projetil: {
				buffer << "PROJETIL" << " ";
				break;
			}
			case Id::Plataforma: {
				buffer << "PLATAFORMA" << " ";
				break;
			}
			case Id::Estrutura:{
				buffer << "ESTRUTURA" << " ";
				break;
			}
			default: {
				break;
			}
		}

		buffer << idUnico << " ";
		buffer << ativo << " ";
		buffer << getPosition().x << " ";
		buffer << getPosition().y << " ";

		buffer << speed.x << " ";
		buffer << speed.y << " ";
	}

	void Entidade::desativar(){
		ativo = 0;
	}
	bool Entidade::ativado() const
	{
		return ativo;
	}

	void Entidade::setId(int id)
	{
		idUnico = id;
	}

	void Entidade::setAtivo(bool at)
	{
		ativo = at;
	}

	void Entidade::setPosicao(float x, float y)
	{
		shape.setPosition(x, y);
	}

	void Entidade::setVelocidade(float x, float y)
	{
		speed.x = x;
		speed.y = y;
	}

	

}