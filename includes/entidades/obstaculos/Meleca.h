#ifndef JOGO_MELECA_H
#define JOGO_MELECA_H
#include "Obstaculo.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {

            class Meleca: public Obstaculo
            {
            private:
                static int instancias;

                int viscosidade;
                float tamMaximo;
                float tamMinimo;
                bool aumentando;

            public:
                Meleca(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_viscosidade);
                Meleca();
                ~Meleca();

                void executar() override;
                void obstaculizar(Entidade *entidade) override;

                void salvar() override;

                static int getInstancias();
                static void setInstancias(int instancias);
            };

        }
    }
}




#endif //JOGO_MELECA_H