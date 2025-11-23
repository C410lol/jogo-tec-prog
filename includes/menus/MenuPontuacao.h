#ifndef JOGO_MENUPONTUACAO_H
#define JOGO_MENUPONTUACAO_H

#include "menus/Menu.h"
#include "menus/CaixaTexto.h"




namespace jogo {
    namespace menus {

        class MenuPontuacao: public Menu
        {
        private:
            CaixaTexto *pCaixaTexto;
            std::string username;

        public:
            MenuPontuacao();
            ~MenuPontuacao();

            void executar() override;
            void atualizar() override;
            void desenhaMenu() override;

            void salvarPontuacao();
        };

    }
}




#endif //JOGO_MENUPONTUACAO_H