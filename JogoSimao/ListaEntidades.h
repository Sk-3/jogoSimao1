#pragma once

#include "Lista.h"
#include "Entidade.h"
#include <vector>
#include <set>
#include <list>




#include "Estrutura.h"
#include "projetil.h"
#include "Obstaculo.h"
namespace Entidades {
    namespace Personagens{
        class Personagem;
    }
}

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidade*> lista;
        Lista<Entidades::Entidade*>::Iterator it;
        std::vector<Entidades::Estrutura*> estruturas;
        std::vector<Entidades::Personagens::Personagem*> personagens;
        std::list<Entidades::Obstaculos::Obstaculo*> obstaculos;
        std::set<Entidades::Projetil*> projeteis;

    public:
        ListaEntidades();
        ~ListaEntidades();

        void limpar();
        void inserirNoFim(Entidades::Entidade* ent);
        void inserirNoInicio(Entidades::Entidade* ent);
        void removerDoInicio();
        void removerDoFim();
        const int getTam() const;
        Lista<Entidades::Entidade*>::Iterator apagar(Lista<Entidades::Entidade*>::Iterator iter);
        Lista<Entidades::Entidade*>::Iterator inicio();
        Lista<Entidades::Entidade*>::Iterator fim();



        //GETTERS
        std::set<Entidades::Projetil*>* getProjeteis();
        std::list<Entidades::Obstaculos::Obstaculo*>* getObstaculos();
        std::vector<Entidades::Estrutura*>* getEstruturas();
        std::vector<Entidades::Personagens::Personagem*>* getPersonagens();

        void executar();
        void salvar();
        void desenhar();
        void desalocar();
    };
} using namespace Listas;