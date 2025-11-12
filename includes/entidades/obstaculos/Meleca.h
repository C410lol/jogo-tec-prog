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
                float tamMaximo;
                float tamMinimo;
                bool aumentando;

            public:
                static int instancias;
            public:
                Meleca(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_viscosidade);
                Meleca();
                ~Meleca();

                void executar() override;
                void obstaculizar(Entidade *entidade) override;
            };

        }
    }
}




#endif //JOGO_MELECA_H