#include "Cachorro.h"
#include "EstadoCachorroAtacar.h"

namespace Entidades {
	namespace Personagens {
		EstadoCachorroAtacar::EstadoCachorroAtacar()
		{
			id = 1;
		}

		EstadoCachorroAtacar::~EstadoCachorroAtacar()
		{
		}
		void EstadoCachorroAtacar::atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao)
		{
			/**
			*@brief Funcao responsavel por fazer o cachorro atacar o jogador caso ele esteja vivo
			*@param ponteiro pro objeto cachorro
			*/
			if (cachorro->getPlayer() && cachorro->getPlayer()->getHealth() >= 0) {
				cachorro->setMoveSpeed(cachorro->getVelocidadeCacando());				
				if (cachorro->jogadorNoAlcance()) {
					cachorro->perseguirJogador();
					cachorro->atirar(lista, gerColisao);
				}
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