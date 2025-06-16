#include "ListaEntidades.h"
#include "Estrutura.h"
#include "Obstaculo.h"
#include "Personagem.h"
#include "Projetil.h"
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
        if (ent){
            lista.inserirNoFim(ent);
            switch (ent->getTipoEntidade()) {
            case TipoEntidade::ESTRUTURA: {
                estruturas.emplace_back(static_cast<Entidades::Estrutura*>(ent));
                break;
            }
            case TipoEntidade::OBSTACULO: {
                obstaculos.push_back(static_cast<Entidades::Obstaculos::Obstaculo*>(ent));
                break;
            }
            case TipoEntidade::PERSONAGEM: {
                personagens.emplace_back(static_cast<Entidades::Personagens::Personagem*>(ent));
                break;
            }
            case TipoEntidade::PROJETIL: {
                projeteis.emplace(static_cast<Entidades::Projetil*>(ent));
                break;
            }
            default:
                break;

            }
        }
    }

    void ListaEntidades::inserirNoInicio(Entidades::Entidade* ent)
    {
        if (ent){
            lista.inserirNoInicio(ent);

            switch (ent->getTipoEntidade()) {
            case TipoEntidade::ESTRUTURA: {
                estruturas.emplace_back(static_cast<Entidades::Estrutura*>(ent));
                break;
            }
            case TipoEntidade::OBSTACULO:{
                obstaculos.push_back(static_cast<Entidades::Obstaculos::Obstaculo*>(ent));
                break; 
            }
            case TipoEntidade::PERSONAGEM: {
               personagens.emplace_back(static_cast<Entidades::Personagens::Personagem*>(ent));
               break;
            }
            case TipoEntidade::PROJETIL: {
                projeteis.emplace(static_cast<Entidades::Projetil*>(ent));
                break;
            }
            default:
                break;

            }
        }
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

    std::set<Entidades::Projetil*>* ListaEntidades::getProjeteis()
    {
        return &projeteis;
    }

    std::list<Entidades::Obstaculos::Obstaculo*>* ListaEntidades::getObstaculos()
    {
        return &obstaculos;
    }

    std::vector<Entidades::Estrutura*>* ListaEntidades::getEstruturas()
    {
        return &estruturas;
    }

    std::vector<Entidades::Personagens::Personagem*>* ListaEntidades::getPersonagens()
    {
        return &personagens;
    }

    void ListaEntidades::executar()
    {
        for (it = inicio(); it != fim(); ++it)
            if ((*it)->Ativado()) {
                (*it)->executar();
            }
    }

    

    void ListaEntidades::salvar()
    {
        //for (it = inicio(); it != fim(); ++it)
            //(*it)->salvar();
    }

    void ListaEntidades::desenhar()
    {
        for (it = inicio(); it != fim(); ++it)
            if((*it)->Ativado()){
                (*it)->desenhar();
            }
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