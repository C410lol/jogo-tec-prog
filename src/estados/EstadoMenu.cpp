#include "estados/EstadoMenu.h"
#include "gerenciadores/GerenciadorEstado.h"
#include "menus/MenuPausa.h"
#include "menus/MenuPrincipal.h"
#include "menus/MenuJogadores.h"




namespace jogo {
    namespace estados {
        EstadoMenu::EstadoMenu(IDs id, IDs r_fase) : Estado(id), menu(nullptr), fase(r_fase) {
            criarMenu();
        }
        EstadoMenu::~EstadoMenu() {

        }
        void EstadoMenu::executar() {
            voltaMenu = false;
           menu->executar();
        }
        void EstadoMenu::criarMenu() {
            switch (Id) {
                case IDs::menu_principal:
                    menu = new menus::MenuPrincipal();
                    break;
                case IDs::menu_jogadores:
                    menu = new menus::MenuJogadores(fase);
                    break;
                case IDs::menu_pausa:
                    menu = new menus::MenuPausa();
                    break;
                default:
                    break;
            }
        }

    }
}
