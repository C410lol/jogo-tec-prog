#ifndef JOGO_PLATAFORMA_H
#define JOGO_PLATAFORMA_H

#include "Obstaculo.h"
#include <SFML/System/Vector2.hpp>

#include "dtos/ObstaculoDTO.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {
            class Plataforma : public Obstaculo {
            private:
                static int numInstancias;

                bool ehChao;
                bool invisivel;

            public:
                Plataforma(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, bool r_ehChao, IDs id);

                Plataforma(dtos::ObstaculoDTO obsDTO, bool r_ehChao, bool r_invisivel);

                Plataforma();

                ~Plataforma();

                void executar() override;

                void obstaculizar(Entidade *entidade) override;

                void salvar() override;

                void atualizarInvisibilidade();

                static int getInstancias();

                static void setInstancias(int instancias);
            };
        }
    }
}


#endif //JOGO_PLATAFORMA_H