#ifndef JOGO_OBSTACLE_H
#define JOGO_OBSTACLE_H

#include "dtos/ObstaculoDTO.h"
#include "entidades/Entidade.h"




namespace jogo {
    namespace entidades {
        namespace obstaculos {

            class Obstaculo: public Entidade
            {
            protected:
                bool danoso;
                double cooldown;

            public:
                Obstaculo(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso);
                Obstaculo(dtos::ObstaculoDTO obsDTO);
                Obstaculo();
                virtual ~Obstaculo();

                virtual void executar() = 0;
                virtual void obstaculizar(Entidade *entidade) = 0;

                virtual void salvar();
            };

        }
    }
}




#endif //JOGO_OBSTACLE_H