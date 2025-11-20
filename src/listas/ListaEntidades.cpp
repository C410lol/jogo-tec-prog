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




        void ListaEntidades::salvarEntidades()
        {
            std::ofstream file("../salvamentos/salvamento.txt");

            std::cout << LEs.getSize() << std::endl;

            std::cout << "asdasdasd" << std::endl;

            entidades::Entidade* entidade = nullptr;
            for (int i = 0; i < LEs.getSize(); ++i)
            {
                std::cout << "b";
                entidade = LEs[i];
                if (!entidade)
                    continue;

                std::cout << "a" << std::endl;

                entidade->salvar();
                file << entidade->getBufferString() << std::endl;
            }

            std::cout << "ccccccccccccccccc" << std::endl;

            file.close();
        }


    }  // namespace Listas
}
