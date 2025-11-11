#include "entidades/Entidade.h"
#include "listas/Lista.h"
#include "listas/ListaEntidades.h"


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
                if (aux)
                    aux->executar();
                if (aux)
                    aux->desenhar();
            }
        }

    }  // namespace Listas
}