#ifndef JOGO_OBSTACLE_H
#define JOGO_OBSTACLE_H

#include "entidades/Entidade.h"




namespace jogo {
    namespace entidades {
        namespace obstaculos {

            class Obstaculo: public Entidade
            {
            protected:
                bool danoso;

            public:
                Obstaculo();
                virtual ~Obstaculo();

                void executar() override;
                virtual void obstaculizar(Entidade *entidade);

                virtual void colidir(Entidade *pEntidade);
            };

        }
    }
}




#endif //JOGO_OBSTACLE_H