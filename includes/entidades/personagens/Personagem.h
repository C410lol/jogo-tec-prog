#ifndef JOGO_CHARACTER_H
#define JOGO_CHARACTER_H

#include "entidades/Entidade.h"




namespace jogo {
    namespace entidades {
        namespace personagens {

            #define JOGADOR_VIDAS 3
            #define GRAVIDADE 0.1

            class Personagem: public Entidade
            {
            protected:
                int vidas;

            public:
                Personagem();
                ~Personagem() override;

                void exec() override = 0;

                virtual void deslocar() = 0;
                virtual void cair();

            };

        }
    }
}




#endif //JOGO_CHARACTER_H