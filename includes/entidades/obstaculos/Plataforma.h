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
                static int instancias;

                bool ehChao;
                bool invisivel;

            public:
                Plataforma(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso, bool r_ehChao);
                Plataforma();
                ~Plataforma();

                void executar() override;
                void obstaculizar(Entidade *entidade) override;

                void atualizarInvisibilidade();

                static int getInstancias();
            };

        }
    }
}




#endif //JOGO_PLATAFORMA_H