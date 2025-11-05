#ifndef JOGO_PLAYER_H
#define JOGO_PLAYER_H

#include "entidades/personagens/Personagem.h"




namespace jogo {
    namespace entidades {
        namespace personagens {

            class Jogador: public Personagem
            {
            private:
                float deslocamentoX;
                bool naMeleca;
                int pontos;
            private:
                void atualizarNaMeleca();

            public:
                Jogador();
                ~Jogador() override;

                void executar() override;
                void deslocar() override;
                void colidir(Entidade *pEntidade) override;
                void checarEstaMorto() const;

                void setNaMeleca(bool r_estaNaMeleca);

                void pular();
            };

        }
    }

}




#endif //JOGO_PLAYER_H