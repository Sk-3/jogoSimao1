#include "EstadoCachorroSeguir.h"
#include "Cachorro.h"
#include "EstadoCachorroCacar.h"
namespace Entidades {
	namespace Personagens {
		
		EstadoCachorroSeguir::EstadoCachorroSeguir()
		{
			id = 2;
			seguir = false;
			if ((rand() % 10) < 7) // 70% de chance de seguir o dono
			{
				seguir = true;
			}			
		}
		EstadoCachorroSeguir::~EstadoCachorroSeguir()
		{
		}

		void EstadoCachorroSeguir::atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao)
		{
			if (seguir)
			{
				cachorro->seguirDono();
			}			
		}
		
	}
}