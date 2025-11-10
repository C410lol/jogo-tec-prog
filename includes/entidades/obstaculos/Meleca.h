#ifndef JOGO_MELECA_H
#define JOGO_MELECA_H
#include "Obstaculo.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            class Meleca: public Obstaculo
            {
            private:
                int viscosidade;

            public:
                static int instancias;
            public:
                Meleca(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_viscosidade);
                Meleca();
                ~Meleca();

                void obstaculizar(Entidade *entidade) override;
            };

        }
    }
}




#endif //JOGO_MELECA_H