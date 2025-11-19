

#include "estados/EstadoMenu.h"

#include <iostream>

#include "gerenciadores/GerenciadorEstado.h"
#include "menus/MenuPausa.h"
#include "menus/MenuPrincipal.h"

namespace jogo {
    namespace estados {
        EstadoMenu::EstadoMenu(IDs id) : Estado(id), menu(nullptr){
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
                case IDs::menu_principal: {
                    menu = new menus::MenuPrincipal();
                    break;
                }
                case IDs::menu_pausa: {
                    menu = new menus::MenuPausa();
                    break;
                }



            }
        }
    }
}
