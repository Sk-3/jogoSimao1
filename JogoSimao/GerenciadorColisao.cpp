#include "GerenciadorColisao.h"
namespace Gerenciadores{

	void GerenciadorColisao::executar()
	{
		colision();
	
	}
	GerenciadorColisao::GerenciadorColisao():Ente(), characters(nullptr), obstaculos(nullptr), projeteis(nullptr)
	{
	
	}
	GerenciadorColisao::GerenciadorColisao(std::vector<Entidades::Personagens::Character*>* characters, std::vector<Entidades::Obstaculos::Obstaculo*>* obstaculos, std::vector<Entidades::Projetil*>* projeteis)
		:Ente()
	{
		this->projeteis = projeteis;
		this->obstaculos = obstaculos;
		this->characters = characters;
	}

	GerenciadorColisao::~GerenciadorColisao()
	{
	
	}

	void GerenciadorColisao::colision()
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



		for (auto& charact : *characters) {
			sf::FloatRect characterBounds = charact->getBounds();
			for (const auto& obstac : *obstaculos) {
				sf::FloatRect obstaculoBounds = obstac->getBounds();

				if (characterBounds.intersects(obstaculoBounds)) {
					obstac->setIsColiding(1);
				

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
							charact->hitRight(obstac); 
						}
						else {
							// Personagem est� mais � direita que o centro do obst�culo,
							// ent�o o lado ESQUERDO do personagem colidiu com o lado DIREITO do obst�culo.
							charact->hitLeft(obstac);
						}
					}
					else {
					
						if (charCenterY < obstCenterY) {
							// Personagem est� mais acima que o centro do obst�culo,
							// ent�o a parte de BAIXO do personagem colidiu com a parte de CIMA do obst�culo.
							charact->hitGround(obstac);
						}
						else {
							// Personagem est� mais abaixo que o centro do obst�culo,
							// ent�o a parte de CIMA do personagem colidiu com a parte de BAIXO do obst�culo.
							charact->hitTop(obstac);
						}
					}

				}
				else {
					obstac->setIsColiding(0);
				}

			}
		}
	}

}