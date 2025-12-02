#ifndef JOGO_ESPINHO_H
#define JOGO_ESPINHO_H
#include "Obstaculo.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {
            class Espinho : public Obstaculo {
            private:
                static int numInstancias;

                int danosidade;
                float disMax;
                float disMin;
                bool deslocandoEsquerda;

            public:
                Espinho(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, int r_danosidade);

                Espinho
                (
                    dtos::ObstaculoDTO obsDTO, int r_danosidade, float r_disMax,
                    float r_disMin, bool r_deslocandoEsquerda
                );

                Espinho();

                ~Espinho();

                void executar() override;

                void obstaculizar(Entidade *entidade) override;

                void salvar() override;

                static int getInstancias();

                static void setInstancias(int instancias);
            };
        }
    }
}


#endif //JOGO_ESPINHO_H