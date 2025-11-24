
#ifndef JOGO_MENU_H
#define JOGO_MENU_H
#include "Botao.h"
#include "../Ente.h"


namespace jogo::gerenciadores {
    class GerenciadorEstado;
}

namespace jogo
{
    class Jogo;

    class Menu:public Ente
    {
    protected:
        static Jogo *pjogo;
        std::vector<menus::Botao*> botoes;
        gerenciadores::GerenciadorEstado *pge;
    public:
        Menu(Jogo *r_pjogo);
        Menu();
        ~Menu();

        void executar() override;
        virtual void atualizar() = 0;
        virtual void desenhaMenu() = 0;
        IDs exec();
    };
}
#endif //JOGO_MENU_H