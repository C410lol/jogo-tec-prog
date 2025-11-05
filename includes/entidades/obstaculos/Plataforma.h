#ifndef JOGO_PLATAFORMA_H
#define JOGO_PLATAFORMA_H

#include "Obstaculo.h"
#include <SFML/System/Vector2.hpp>




namespace jogo {
    namespace entidades {
        namespace obstaculos {

            class Plataforma: public Obstaculo
            {
            private:
                bool movel;

            public:
                Plataforma(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, bool r_movel);
                Plataforma();
                ~Plataforma();

                void obstaculizar(Entidade *entidade) override;
            };

        }
    }
}




#endif //JOGO_PLATAFORMA_H