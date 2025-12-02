//
// Created by mvmko on 18/11/2025.
//

#ifndef JOGO_MENUPRINCIPAL_H
#define JOGO_MENUPRINCIPAL_H
#include "Menu.h"


#include "Menu.h"
#include "Botao.h"

namespace jogo {
    namespace menus {
        class MenuPrincipal : public Menu {
        private:
            IDs carregarFaseContinuar();

        public:
            MenuPrincipal();

            ~MenuPrincipal();

            void atualizar() override;

            void desenhaMenu();

            void executar();
        };
    }
}
#endif //JOGO_MENUPRINCIPAL_H