#include "listas/ListaEntidades.h"

#include "entidades/personagens/inimigos/Inimigo.h"


namespace jogo {
    namespace listas {

        ListaEntidades::ListaEntidades() = default;
        ListaEntidades::~ListaEntidades() = default;


        void ListaEntidades::incluir(entidades::Entidade *pEntidade)
        {
            listaEntidades.incluir(pEntidade);
        }
        void ListaEntidades::percorrer()
        {
            Lista<entidades::Entidade*>::Iterator it;
            for (it = listaEntidades.begin(); it != listaEntidades.end(); ++it)
            {
                if (*it)
                {
                    (*it)->executar();
                }
            }
        }
    void ListaEntidades::setJogadoralvo(entidades::personagens::Jogador* pjog)
    {
            Lista<entidades::Entidade*>::Iterator it;
            for (it = listaEntidades.begin(); it != listaEntidades.end(); ++it)
            {
                entidades::personagens::inimigos::Inimigo* pInimigo= dynamic_cast<entidades::personagens::inimigos::Inimigo*>(*it);
                if (pInimigo)
                    pInimigo->setJogadoralvo(pjog);
            }
    }

    }
}
