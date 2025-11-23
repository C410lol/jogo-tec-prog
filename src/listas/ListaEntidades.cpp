#include "entidades/Entidade.h"
#include "listas/Lista.h"
#include "listas/ListaEntidades.h"

#include <fstream>
#include <iostream>


namespace jogo {
    namespace listas {

        ListaEntidades::ListaEntidades() : LEs() {}

        ListaEntidades::~ListaEntidades() { limpar(); }

        void ListaEntidades::incluir(entidades::Entidade *e) {
            if (e != nullptr) LEs.incluir(e);
        }

        void ListaEntidades::deletar(entidades::Entidade *e) {
            if (e != nullptr) LEs.remover(e);
        }

        const int ListaEntidades::getSize() const { return LEs.getSize(); }

        void ListaEntidades::limpar() { LEs.limpar(); }

        Lista<entidades::Entidade>::Iterator ListaEntidades::begin() {
            return LEs.begin();
        }
        Lista<entidades::Entidade>::Iterator ListaEntidades::end() {
            return LEs.end();
        }

        void ListaEntidades::executar() {
            entidades::Entidade *aux = nullptr;
            for (int i = 0; i < LEs.getSize(); i++) {
                aux = LEs.operator[](i);
                if (aux) {
                    if (aux->getAtivo())
                    {
                        aux->executar();
                        aux->desenhar();
                    }
                    else
                    {
                        deletar(aux);
                    }
                }
            }
        }




        void ListaEntidades::salvarEntidades(IDs fase)
        {
            std::ofstream file("../salvamentos/salvamento.txt");

            //  Insere qual a fase
            if (fase == IDs::primeira_fase)
                file << "1";
            else if (fase == IDs::segunda_fase)
                file << "2";
            file << std::endl;

            entidades::Entidade* entidade = nullptr;
            for (int i = 0; i < LEs.getSize(); ++i)
            {
                entidade = LEs[i];
                if (!entidade)
                    continue;

                entidade->salvar();
                file << entidade->getBufferString() << std::endl;
            }

            file.close();
        }
        entidades::Entidade *ListaEntidades::procurarPeloId(int id)
        {
            entidades::Entidade *pEntidade = nullptr;
            for (int i = 0; i < LEs.getSize(); ++i)
            {
                pEntidade = LEs[i];
                if (!pEntidade)
                    continue;

                if (pEntidade->getIdNumber() == id)
                    return pEntidade;
            }

            return nullptr;
        }

    }  // namespace Listas
}
