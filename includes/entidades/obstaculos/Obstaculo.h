#ifndef JOGO_OBSTACLE_H
#define JOGO_OBSTACLE_H

#include "entidades/Entidade.h"




namespace jogo {
    namespace entidades {
        namespace obstacles {
            class Obstaculo: public Entidade
            {
            protected:
                bool danoso;

            public:
                Obstaculo();
                virtual ~Obstaculo();

                void exec() override;
                virtual void obstaculizar(Entidade &entidade);
            };
        }
    }
}




#endif //JOGO_OBSTACLE_H