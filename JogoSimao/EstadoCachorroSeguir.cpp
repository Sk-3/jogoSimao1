#include "EstadoCachorroSeguir.h"
#include "Cachorro.h"
#include "EstadoCachorroCacar.h"
namespace Entidades {
	namespace Personagens {
		
		EstadoCachorroSeguir::EstadoCachorroSeguir()
		{
			id = 2;
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