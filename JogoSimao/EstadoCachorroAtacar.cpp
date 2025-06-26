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
		void EstadoCachorroAtacar::atualizar(Cachorro* cachorro)
		{
			cachorro->setMoveSpeed(velAtaque);
			if (cachorro->getPlayer() && cachorro->getPlayer()->getHealth() >= 0) {								
				if (cachorro->jogadorNoAlcance()) {
					cachorro->perseguirJogador();
					cachorro->atirar();
				}
			}			
		}

	}
}