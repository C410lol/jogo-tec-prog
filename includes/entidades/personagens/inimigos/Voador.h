#ifndef JOGO_FLYING_H
#define JOGO_FLYING_H

#include "entidades/personagens/inimigos/Inimigo.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                class Voador: public Inimigo
                {
                private:

                public:
                    Voador(Jogador *r_pJogador);
                    ~Voador();

                    void deslocar() override;
                };

            }
        }
    }
}




#endif //JOGO_FLYING_H