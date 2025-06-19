#include "GerenciadorColisao.h"
#include <iostream>
namespace Gerenciadores{

	void GerenciadorColisao::executar()
	{
		colision();
	
	}
	GerenciadorColisao::GerenciadorColisao()
	{
		jogador1 = nullptr;
		jogador2 = nullptr;
	
	}

	GerenciadorColisao::~GerenciadorColisao()
	{
	
	}

	const bool GerenciadorColisao::verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2)
	{
		if (!pe1->ativado() || !pe2->ativado()) {
			return 0;
		}
		sf::FloatRect ent1Bounds = pe1->getBounds();
		sf::FloatRect ent2Bounds = pe2->getBounds();
		return ent1Bounds.intersects(ent2Bounds);
	}

	void GerenciadorColisao::tratarColisoesJogsObstaculos()
	{
		if(jogador1){
			for (auto& obstac : obstaculos) {
				if (verificarColisao(obstac, jogador1)) {
					if (obstac->ehColidivel()) {
						empurrarPersonagem(jogador1, obstac);
					}
					obstac->obstacular(jogador1);
				}
			}
			
		}
		if (jogador2) {
			for (auto& obstac : obstaculos) {
				if (verificarColisao(obstac, jogador2)) {
					if (obstac->ehColidivel()) {
						empurrarPersonagem(jogador2, obstac);
					}
					obstac->obstacular(jogador2);
				}
			}
			
		}


	}

	void GerenciadorColisao::tratarColisoesJogsEstruturas()
	{
		if (jogador1) {
			for (auto& estrutur : estruturas) {
				if (verificarColisao(estrutur, jogador1)) {
					empurrarPersonagem(jogador1, estrutur);
				}
			}
		}
		if (jogador2) {
			for (auto& estrutur : estruturas) {
				if (verificarColisao(estrutur, jogador2)) {
					empurrarPersonagem(jogador2, estrutur);
				}
			}
		}
	}

	void GerenciadorColisao::tratarColisaoProjeteis()
	{
		for (auto& projet : projeteis) {
			if (projet->ativado()) {
				sf::FloatRect projBounds = projet->getBounds();
				for (const auto& obst : obstaculos) {
					if (verificarColisao(obst, projet)) {
						projet->desativar();
					}
				}
				for (const auto& estrut : estruturas) {
					if (verificarColisao(estrut, projet)) {
						projet->desativar();
					}
				}

				for (auto& charact : inimigos) {
					if (verificarColisao(projet, charact)) {
						if (charact->getTipo() != projet->getTipo()) {
							projet->desativar();
							projet->danifica(charact);
							projet->aumentaPontosDono();
							
						}
					}
				}

				if (verificarColisao(projet, jogador1)) {
					if (projet->getTipo() == TipoPersonagem::INIMIGO) {
						projet->danifica(jogador1);
						projet->desativar();
					}
				}
				if (jogador2) {
					if (verificarColisao(projet, jogador2)) {
						if (projet->getTipo() == TipoPersonagem::INIMIGO) {
							projet->danifica(jogador2);
							projet->desativar();
						}
					}
				}
			}
		}
	}

	void GerenciadorColisao::tratarColisaoInimigos()
	{
		for (auto& charact : inimigos) {
			if(charact->ativado()){
				for (const auto& obstac : obstaculos) {
					if (verificarColisao(obstac, charact)) {
						if (obstac->ehColidivel()) {
							empurrarPersonagem(charact, obstac);
						}
						obstac->obstacular(charact);
					}
				}
			}
		}

		
	


		for (auto& charact : inimigos) {
			if(charact->ativado()){
				for (const auto& estrut : estruturas) {
					if (verificarColisao(estrut, charact)) {
					
						empurrarPersonagem(charact, estrut);
					
					}
				}
			}
		}
	}

	void GerenciadorColisao::incluirInimigo(Entidades::Personagens::Inimigo* inimigo)
	{
		inimigos.emplace_back(inimigo);
	}

	void GerenciadorColisao::incluirObstaculo(Entidades::Obstaculos::Obstaculo* obstaculo)
	{
		std::cout << "obstaculo incluido";
		obstaculos.emplace_back(obstaculo);
	}

	void GerenciadorColisao::incluirProjetil(Entidades::Projetil* projetil)
	{
		projeteis.emplace_back(projetil);
	}

	void GerenciadorColisao::incluirEstrutura(Entidades::Estrutura* estrutura)
	{
		estruturas.emplace_back(estrutura);
	}

	void GerenciadorColisao::incluirJogador1(Entidades::Personagens::Jogador* jogador)
	{
		jogador1 = jogador;
	}
	void GerenciadorColisao::incluirJogador2(Entidades::Personagens::Jogador* jogador)
	{
		jogador2 = jogador;
	}
	void GerenciadorColisao::empurrarPersonagem(Entidades::Personagens::Personagem* personagem, Entidades::Entidade* entidade)
	{

		/**
		*@Autor Felipe Simbalista
		* 
		*@brief Realiza a lógica de empurrar o personagem com base no tamanho das intercecoes dos eixos X e Y com o objeto
		*@param personagem: Referência para um personagem
		*@param obstaculo: Referencia para um obstaculo
		*
		*/
		sf::FloatRect characterBounds = personagem->getBounds();
		sf::FloatRect entBounds = entidade->getBounds();
		
		//Centro do personagem
		float charCenterX = characterBounds.left + characterBounds.width / 2.f;
		float charCenterY = characterBounds.top + characterBounds.height / 2.f;

		//Centro do obstaculo
		float entCenterX = entBounds.left + entBounds.width / 2.0f;
		float entCenterY = entBounds.top + entBounds.height / 2.0f;

		//Sobreposição em cada eixo

		float overlapX = std::min(characterBounds.left + characterBounds.width, entBounds.left + entBounds.width) - std::max(characterBounds.left, entBounds.left);
		//interseção no eixo X


		float overlapY = std::min(characterBounds.top + characterBounds.height, entBounds.top + entBounds.height) - std::max(characterBounds.top, entBounds.top);
		//interseção no eixo y

		// Determinar a direção da colisão pela menor sobreposição
		if (overlapX < overlapY) {
			if (charCenterX < entCenterX) {
				// Personagem está mais à esquerda que o centro do obstáculo,
				// então o lado DIREITO do personagem colidiu com o lado ESQUERDO do obstáculo.
				personagem->colidiu(entidade, Directions::RIGHT);
			}
			else {
				// Personagem está mais à direita que o centro do obstáculo,
				// então o lado ESQUERDO do personagem colidiu com o lado DIREITO do obstáculo.
				personagem->colidiu(entidade, Directions::LEFT);
			}
		}
		else {

			if (charCenterY < entCenterY) {
				// Personagem está mais acima que o centro do obstáculo,
				// então a parte de BAIXO do personagem colidiu com a parte de CIMA do obstáculo.
				personagem->colidiu(entidade, Directions::DOWN);
			}
			else {
				// Personagem está mais abaixo que o centro do obstáculo,
				// então a parte de CIMA do personagem colidiu com a parte de BAIXO do obstáculo.
				personagem->colidiu(entidade, Directions::UP);
			}
		}
	}

	

	void GerenciadorColisao::colision()
	{
		/**
		* Felipe simbalista
		* @brief Verifica colisões entre personagens, obstáculos e projéteis.
		* @details Esta função percorre os vetores de personagens, obstáculos e projéteis, verificando se há interseção entre eles.
		* caso haja interseção, as ações apropriadas são executadas, como desativar projéteis ou aplicar dano aos personagens.
		* @return void
		*/
		tratarColisaoProjeteis();
		tratarColisaoInimigos();
		tratarColisoesJogsObstaculos();
		tratarColisoesJogsEstruturas();
		
	}

}