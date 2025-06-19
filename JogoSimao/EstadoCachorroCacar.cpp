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

		void EstadoCachorroCacar::atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao)
		{
			/**
			*@brief Funcao responsavel por fazer o cachorro perseguir o jogador caso ele esteja vivo
			*@param ponteiro pro objeto cachorro
			*/
			if (cachorro->getPlayer() && cachorro->getPlayer()->getHealth() >= 0) {
				cachorro->setMoveSpeed(cachorro->getVelocidadeCacando());
				cachorro->perseguirJogador();
				if (cachorro->jogadorNoAlcance()) {
					cachorro->atirar(lista, gerColisao);
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
