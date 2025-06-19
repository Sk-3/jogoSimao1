#pragma once
#include "ListaEntidades.h"
#include "GerenciadorColisao.h"

namespace Entidades{
	namespace Personagens{
		class Cachorro;
		class Personagem;

		class EstadoCachorro
		{
		public:
			virtual ~EstadoCachorro(){}
			virtual void atualizar(Cachorro* cachorro, ListaEntidades* lista, Gerenciadores::GerenciadorColisao* gerColisao) = 0;
			virtual void entrar(Cachorro* cachorro) = 0;
			virtual void sair(Cachorro* cachorro) = 0;
		};
	}
}