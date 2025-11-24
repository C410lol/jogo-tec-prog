


#include "estados/Estado.h"

namespace jogo {
    namespace estados {

        gerenciadores::GerenciadorEstado *Estado::pGE = nullptr;
        void Estado::setGE(gerenciadores::GerenciadorEstado *r_pGE)
        {
            pGE = r_pGE;
        }




        Estado::Estado(const IDs ID):
                    Ente(), remover(false), voltaMenu(false)
        {
            Id=ID;
        }
        bool Estado::getvoltaMenu() {
            return voltaMenu;
        }
        void Estado::setvoltaMenu(const bool voltaMenu) {
            this->voltaMenu = voltaMenu;
        }

    }
}
