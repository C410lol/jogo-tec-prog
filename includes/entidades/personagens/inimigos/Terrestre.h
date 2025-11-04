#ifndef JOGO_LAND_H
#define JOGO_LAND_H

#include "entidades/personagens/inimigos/Inimigo.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                #define TERRESTRE_RAIO_MAX 200

                class Terrestre: public Inimigo
                {
                private:

                public:
                    Terrestre(Jogador *r_pJogador);
                    ~Terrestre();

                    void deslocar() override;
                    void colidir(Entidade *pEntidade) override;
                };

            }
        }
    }
}




#endif //JOGO_LAND_H