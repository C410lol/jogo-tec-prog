#ifndef JOGO_ENEMY_H
#define JOGO_ENEMY_H

#include "entidades/personagens/Personagem.h"
#include "entidades/personagens/Jogador.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                #define VELOCIDADE 3.f

                class Inimigo: public Personagem
                {
                protected:
                    Jogador *pJogadorAlvo;

                public:
                    Inimigo(Jogador *r_pJogadorAlvo);
                    virtual ~Inimigo();

                    void executar() override;
                    virtual void deslocar() = 0;

                    virtual void colidir(Entidade *pEntidade) = 0;
                };

            }
        }
    }
}




#endif //JOGO_ENEMY_H