//
// Created by mvmko on 19/11/2025.
//

#ifndef JOGO_MENUPAUSA_H
#define JOGO_MENUPAUSA_H
#include "Menu.h"
#include "fases/Fase.h"

namespace jogo {
    namespace menus {
        class MenuPausa : public Menu {
        private:
            fases::Fase *fase;
            sf::RectangleShape fundoPainel;

        public:
            void atualizar();

            MenuPausa(fases::Fase *fase = nullptr);

            ~MenuPausa();

            void setFase(fases::Fase *fase);

            fases::Fase *getFase();

            virtual void executar();

            void desenhaMenu() override;
        };
    }
}
#endif //JOGO_MENUPAUSA_H