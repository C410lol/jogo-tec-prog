

#ifndef JOGO_BANDEIRA_H
#define JOGO_BANDEIRA_H


#include "Obstaculo.h"
#include "gerenciadores/GerenciadorEstado.h"


namespace jogo {
    namespace entidades {
        namespace obstaculos {
            class Bandeira:public Obstaculo {
            private:
                gerenciadores::GerenciadorEstado* pge;

            public:
                Bandeira(sf::Vector2f r_posicao, sf::Vector2f r_tamanho, bool r_danoso);
                ~Bandeira();

                void executar() override;
                void obstaculizar(Entidade *pEntidade) override;
            };

        }

    }
}

#endif //JOGO_BANDEIRA_H