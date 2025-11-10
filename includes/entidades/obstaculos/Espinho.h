#ifndef JOGO_ESPINHO_H
#define JOGO_ESPINHO_H
#include "Obstaculo.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            class Espinho: public Obstaculo
            {
            private:
                int danosidade;

            public:
                static int instancias;
            public:
                Espinho(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_danosidade);
                Espinho();
                ~Espinho();

                void obstaculizar(Entidade *entidade) override;
            };

        }
    }
}




#endif //JOGO_ESPINHO_H