#ifndef JOGO_ESTADO_H
#define JOGO_ESTADO_H

#include "Ente.h"


namespace jogo {
    namespace gerenciadores {
        class GerenciadorEstado;
    }

    namespace estados {
        class Estado : public Ente {
        private:
            bool remover;

        protected:
            bool voltaMenu;
            static gerenciadores::GerenciadorEstado *pGE;

        public:
            Estado(IDs id);

            virtual ~Estado() = default;

            virtual void executar() = 0;

            bool getvoltaMenu();

            void setvoltaMenu(bool voltaMenu);

            static void setGE(gerenciadores::GerenciadorEstado *r_pGE);
        };
    }
}
#endif //JOGO_ESTADO_H