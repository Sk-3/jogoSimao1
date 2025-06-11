#include "GerenciadorColisao.h"
namespace Gerenciadores{

	void GerenciadorColisao::executar()
	{
		colision();
	
	}
	GerenciadorColisao::GerenciadorColisao(): characters(nullptr), obstaculos(nullptr), projeteis(nullptr)
	{
	
	}
	GerenciadorColisao::GerenciadorColisao(std::vector<Entidades::Personagens::Personagem*>* characters, std::vector<Entidades::Obstaculos::Obstaculo*>* obstaculos, std::vector<Entidades::Projetil*>* projeteis)
		
	{
		/**
		* @brief Construtor da classe GerenciadorColisao.
		* @param characters Ponteiro para vetor de ponteiros para personagens.
		* @param obstaculos Ponteiro para vetor de ponteiros para obst�culos.
		* @param projeteis Ponteiro para vetor de ponteiros para proj�teis.
		* 
		*/
		this->projeteis = projeteis;
		this->obstaculos = obstaculos;
		this->characters = characters;
	}

	GerenciadorColisao::~GerenciadorColisao()
	{
	
	}

	const bool GerenciadorColisao::verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2)
	{
		sf::FloatRect ent1Bounds = pe1->getBounds();
		sf::FloatRect ent2Bounds = pe2->getBounds();
		return ent1Bounds.intersects(ent2Bounds);
	}

	void GerenciadorColisao::tratarColisaoProjeteis()
	{
		for (auto& projet : *projeteis) {
			sf::FloatRect projBounds = projet->getBounds();
			for (const auto& obst : *obstaculos) {
				if (projBounds.intersects(obst->getBounds())) {
					projet->desativar();
				}
			}
			for (auto& charact : *characters) {
				if (projBounds.intersects(charact->getBounds())) {
					if (charact->getTipo() != projet->getTipo()) {
						projet->desativar();
						projet->danifica(charact);
					}
				}
			}
		}
	}

	void GerenciadorColisao::tratarColisaoPersonagens()
	{
		for (auto& charact : *characters) {
			for (const auto& obstac : *obstaculos) {
				if (verificarColisao(obstac, charact)) {
					if (obstac->ehColidivel()) {
						empurrarPersonagem(charact, obstac);
					}
					obstac->obstacular(charact);
				}
			}
		}
	}

	void GerenciadorColisao::empurrarPersonagem(Entidades::Personagens::Personagem* personagem, Entidades::Obstaculos::Obstaculo* obstaculo)
	{

		/**
		*@Autor Felipe Simbalista
		* 
		*@brief Realiza a l�gica de empurrar o personagem com base no tamanho das intercecoes dos eixos X e Y com o objeto
		*@param personagem: Refer�ncia para um personagem
		*@param obstaculo: Referencia para um obstaculo
		*
		*/
		sf::FloatRect characterBounds = personagem->getBounds();
		sf::FloatRect obstaculoBounds = obstaculo->getBounds();
		
		//Centro do personagem
		float charCenterX = characterBounds.left + characterBounds.width / 2.f;
		float charCenterY = characterBounds.top + characterBounds.height / 2.f;

		//Centro do obstaculo
		float obstCenterX = obstaculoBounds.left + obstaculoBounds.width / 2.0f;
		float obstCenterY = obstaculoBounds.top + obstaculoBounds.height / 2.0f;

		//Sobreposi��o em cada eixo

		float overlapX = std::min(characterBounds.left + characterBounds.width, obstaculoBounds.left + obstaculoBounds.width) - std::max(characterBounds.left, obstaculoBounds.left);
		//interse��o no eixo X


		float overlapY = std::min(characterBounds.top + characterBounds.height, obstaculoBounds.top + obstaculoBounds.height) - std::max(characterBounds.top, obstaculoBounds.top);
		//interse��o no eixo y

		// Determinar a dire��o da colis�o pela menor sobreposi��o
		if (overlapX < overlapY) {
			if (charCenterX < obstCenterX) {
				// Personagem est� mais � esquerda que o centro do obst�culo,
				// ent�o o lado DIREITO do personagem colidiu com o lado ESQUERDO do obst�culo.
				personagem->hitRight(obstaculo);
			}
			else {
				// Personagem est� mais � direita que o centro do obst�culo,
				// ent�o o lado ESQUERDO do personagem colidiu com o lado DIREITO do obst�culo.
				personagem->hitLeft(obstaculo);
			}
		}
		else {

			if (charCenterY < obstCenterY) {
				// Personagem est� mais acima que o centro do obst�culo,
				// ent�o a parte de BAIXO do personagem colidiu com a parte de CIMA do obst�culo.
				personagem->hitGround(obstaculo);
			}
			else {
				// Personagem est� mais abaixo que o centro do obst�culo,
				// ent�o a parte de CIMA do personagem colidiu com a parte de BAIXO do obst�culo.
				personagem->hitTop(obstaculo);
			}
		}
	}

	void GerenciadorColisao::colision()
	{
		/**
		* Felipe simbalista
		* @brief Verifica colis�es entre personagens, obst�culos e proj�teis.
		* @details Esta fun��o percorre os vetores de personagens, obst�culos e proj�teis, verificando se h� interse��o entre eles.
		* caso haja interse��o, as a��es apropriadas s�o executadas, como desativar proj�teis ou aplicar dano aos personagens.
		* @return void
		*/
		tratarColisaoProjeteis();
		tratarColisaoPersonagens();

		
	}

}