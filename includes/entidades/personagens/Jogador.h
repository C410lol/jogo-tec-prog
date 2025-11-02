#ifndef JOGO_PLAYER_H
#define JOGO_PLAYER_H

#include "entidades/personagens/Personagem.h"




namespace jogo {
    namespace entidades {
        namespace personagens {

            class Jogador: public Personagem
            {
            private:
                int pontos;

            public:
                Jogador();
                ~Jogador() override;

                void executar() override;
                void deslocar() override;
            };

        }
    }

}




#endif //JOGO_PLAYER_H