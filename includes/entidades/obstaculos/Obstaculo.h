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
                Obstaculo(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso);
                Obstaculo();
                virtual ~Obstaculo();

                void executar() override;
                virtual void obstaculizar(Entidade *entidade) = 0;

                virtual void colidir(Entidade *pEntidade);
            };

        }
    }
}




#endif //JOGO_OBSTACLE_H