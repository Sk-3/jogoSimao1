#include "EstadoCachorroAtacar.h"
#include "Cachorro.h"
#include "EstadoCachorroSeguir.h"

namespace Entidades {
	namespace Personagens {
		EstadoCachorroAtacar::EstadoCachorroAtacar()
		{
		}

		EstadoCachorroAtacar::~EstadoCachorroAtacar()
		{
		}

		void EstadoCachorroAtacar::atualizar(Cachorro* cachorro)
		{
			if (cachorro->getPlayer() && cachorro->getPlayer()->getHealth() >= 0) {
				cachorro->setMoveSpeed(cachorro->getVelocidadeCacando());
				cachorro->perseguirJogador();
			}
			else {
				cachorro->setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroSeguir()));
			}
		}

		void EstadoCachorroAtacar::entrar(Cachorro* cachorro)
		{
			
		}

		void EstadoCachorroAtacar::sair(Cachorro* cachorro)
		{
			
		}

	}
}
