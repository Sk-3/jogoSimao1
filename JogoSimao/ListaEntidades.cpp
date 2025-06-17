#include "ListaEntidades.h"

namespace Listas
{
    ListaEntidades::ListaEntidades()
        : lista(),
        it()
    {
    }

    ListaEntidades::~ListaEntidades()
    {
        limpar();
    }

    void ListaEntidades::limpar()
    {
        lista.limpar();
    }

    void ListaEntidades::inserirNoFim(Entidades::Entidade* ent)
    {
        if (ent)
            lista.inserirNoFim(ent);
    }

    void ListaEntidades::inserirNoInicio(Entidades::Entidade* ent)
    {
        if (ent)
            lista.inserirNoInicio(ent);
    }

    void ListaEntidades::removerDoInicio()
    {
        lista.removerDoInicio();
    }

    void ListaEntidades::removerDoFim()
    {
        lista.removerDoFim();
    }

    const int ListaEntidades::getTam() const
    {
        return lista.getTam();
    }

    Lista<Entidades::Entidade*>::Iterator ListaEntidades::apagar(Lista<Entidades::Entidade*>::Iterator iter)
    {
        return lista.apagar(iter);
    }

    Lista<Entidades::Entidade*>::Iterator ListaEntidades::inicio()
    {
        return lista.inicio();
    }

    Lista<Entidades::Entidade*>::Iterator ListaEntidades::fim()
    {
        return lista.fim();
    }

    void ListaEntidades::executar()
    {
        for (it = inicio(); it != fim(); ++it)
            (*it)->executar();
    }

    

    void ListaEntidades::salvar()
    {
        //for (it = inicio(); it != fim(); ++it)
            //(*it)->salvar();
    }

    void ListaEntidades::desenhar()
    {
        for (it = inicio(); it != fim(); ++it)
            (*it)->desenhar();
    }

    void ListaEntidades::desalocar()
    {
        it = inicio();
        while (it != fim())
        {
            Entidades::Entidade* temp = *it;
            it = apagar(it);
            delete temp;
            ++it;
        }
    }
}