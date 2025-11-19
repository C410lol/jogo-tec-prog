#ifndef JOGO_MENUJOGADORES_H
#define JOGO_MENUJOGADORES_H

#include "menus/Menu.h"




namespace jogo {
    namespace menus {

        class MenuJogadores: public Menu
        {
            IDs fase;
        public:
            MenuJogadores(IDs r_fase = IDs::primeira_fase);
            ~MenuJogadores();

            void executar() override;
            void atualizar() override;
            void desenhaMenu() override;
        };

    }
}




#endif //JOGO_MENUJOGADORES_H