

#ifndef JOGO_ESTADO_H
#define JOGO_ESTADO_H



#include "Ente.h"
namespace jogo {
    namespace estados {
        class Estado:public Ente {
        private:
            bool remover;
            protected:
            bool voltaMenu;
        public:
            Estado(IDs id);
            virtual ~Estado() = default;
            virtual void executar() = 0;
            bool getvoltaMenu();
            void setvoltaMenu(bool voltaMenu);



        };
    }
}
#endif //JOGO_ESTADO_H