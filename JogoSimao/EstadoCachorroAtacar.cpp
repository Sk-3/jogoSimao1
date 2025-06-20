#include "Cachorro.h"
#include "EstadoCachorroAtacar.h"

namespace Entidades {
	namespace Personagens {
		EstadoCachorroAtacar::EstadoCachorroAtacar()
		{
			id = 1;
			velAtaque = 3 + (rand() % 4); // velocidade de ataque entre 3 e 6			
		}

		EstadoCachorroAtacar::~EstadoCachorroAtacar()
		{
		}
		void EstadoCachorroAtacar::atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao, Jogador* jogador)
		{
			cachorro->setMoveSpeed(velAtaque);
			if (jogador && jogador->getHealth() >= 0) {								
				if (cachorro->jogadorNoAlcance()) {
					cachorro->perseguirJogador();
					cachorro->atirar(lista, gerColisao);
				}
			}			
		}

	}
}