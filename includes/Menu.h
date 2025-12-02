#ifndef JOGO_MENU_H
#define JOGO_MENU_H
#include "Ente.h"


namespace jogo {
    class Jogo;

    class Menu : public Ente {
    private:
        Jogo *pjogo;

    public:
        Menu(Jogo *r_pjogo);

        Menu();

        ~Menu();

        void executar() override;
    };
}
#endif //JOGO_MENU_H