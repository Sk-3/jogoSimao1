#include "EstadoCachorroCacar.h"
#include "Cachorro.h"
#include "EstadoCachorroSeguir.h"

namespace Entidades {
	namespace Personagens {
		EstadoCachorroCacar::EstadoCachorroCacar()
		{
			id = 3;
		}

		EstadoCachorroCacar::~EstadoCachorroCacar()
		{
		}

		void EstadoCachorroCacar::atualizar(Cachorro* cachorro)
		{
			/**
			*@brief Funcao responsavel por fazer o cachorro perseguir o jogador caso ele esteja vivo
			*@param ponteiro pro objeto cachorro
			*/
			if (cachorro->getJogador() && cachorro->getJogador()->getHealth() >= 0) {
				cachorro->setMoveSpeed(cachorro->getVelocidadeCacando());
				cachorro->perseguirJogador();
				if (cachorro->jogadorNoAlcance()) {
					cachorro->atirar();
				}
			}
			else {
				cachorro->setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroSeguir()));
			}
		}

		void EstadoCachorroCacar::entrar(Cachorro* cachorro)
		{
			
		}

		void EstadoCachorroCacar::sair(Cachorro* cachorro)
		{
			
		}

	}
}
