#pragma once
namespace Entidades{
	namespace Personagens{
		class Cachorro;
		class Character;

		class EstadoCachorro
		{
		public:
			virtual ~EstadoCachorro(){}
			virtual void atualizar(Cachorro* cachorro) = 0;
			virtual void entrar(Cachorro* cachorro) = 0;
			virtual void sair(Cachorro* cachorro) = 0;
		};
	}
}