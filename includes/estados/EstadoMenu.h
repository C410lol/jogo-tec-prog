//
// Created by mvmko on 18/11/2025.
//

#ifndef JOGO_ESTADOMENU_H
#define JOGO_ESTADOMENU_H
#include "Estado.h"
#include "../menus/Menu.h"
#include "fases/Fase.h"

namespace jogo {
    namespace Gerenciador {
        class GerenciadorEstado;
    }

    namespace estados {
        class EstadoMenu : public Estado {
        private:
            Menu *menu;
            IDs fase;

        public:
            EstadoMenu(IDs id, IDs r_fase = IDs::primeira_fase);

            ~EstadoMenu() override;

            void executar() override;

            void criarMenu();

            Menu *getMenu();
        };
    }
}


#endif //JOGO_ESTADOMENU_H