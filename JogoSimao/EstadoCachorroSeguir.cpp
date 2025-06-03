#include "EstadoCachorroSeguir.h"
#include "Cachorro.h"
#include "EstadoCachorroAtacar.h"
namespace Entidades {
	namespace Personagens {
		
		EstadoCachorroSeguir::EstadoCachorroSeguir() {

		}
		EstadoCachorroSeguir::~EstadoCachorroSeguir()
		{
		}

		void EstadoCachorroSeguir::atualizar(Cachorro* cachorro)
		{
			/**
			*@brief Funcao responsavel por fazer o cachorro perseguir o jogador caso ele esteja vivo
			*@param ponteiro pro objeto cachorro
			*/
			cachorro->setMoveSpeed(cachorro->getVelocidadeSeguindo());
			cachorro->seguirDono();
		}

		void EstadoCachorroSeguir::entrar(Cachorro* cachorro)
		{
		}

		void EstadoCachorroSeguir::sair(Cachorro* cachorro)
		{
		}

		
	}
}