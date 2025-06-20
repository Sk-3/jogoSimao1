#include "EstadoCachorroCacar.h"
#include "Cachorro.h"
#include "EstadoCachorroSeguir.h"

namespace Entidades {
	namespace Personagens {
		EstadoCachorroCacar::EstadoCachorroCacar()
		{
			id = 3;
			alcance = 100 + (100 * (rand() % 10)); // alcance entre 100 e 1000			
		}

		EstadoCachorroCacar::~EstadoCachorroCacar()
		{
		}

		void EstadoCachorroCacar::atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao, Jogador* jogador)
		{
			cachorro->setRange(alcance);
			if (jogador && jogador->getHealth() >= 0) {								
				cachorro->perseguirJogador();
				if (cachorro->jogadorNoAlcance()) {
					cachorro->atirar(lista, gerColisao);
				}
			}
			else {
				cachorro->setEstado(dynamic_cast<EstadoCachorro*>(new EstadoCachorroSeguir()));
			}
		}	

	}
}
