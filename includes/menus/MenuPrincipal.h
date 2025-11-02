#ifndef JOGO_MENUPRINCIPAL_H
#define JOGO_MENUPRINCIPAL_H

#include "menus/Menu.h"




namespace jogo {
    namespace menus {

        class MenuPrincipal: public Menu
        {
        public:
            MenuPrincipal();
            ~MenuPrincipal() override;

            void executar() override;
            void inicializaTexto() override;
            void criarBotoes() override;
        };

    }
}



#endif //JOGO_MENUPRINCIPAL_H