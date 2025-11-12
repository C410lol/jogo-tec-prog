#ifndef JOGO_PLAYER_H
#define JOGO_PLAYER_H

#include "entidades/personagens/Personagem.h"
#include "inimigos/Terrestre.h"


namespace jogo {
    namespace entidades {
        namespace personagens {

            class Jogador: public Personagem
            {
            private:
                static bool primeiroExiste;

                bool ehPrimeiro;
                float deslocamentoX;
                bool naMeleca;
                bool atacando;
                int cooldown;
                int pontos;
            private:
                void atualizarNaMeleca();

            public:
                static int instancias;
            public:
                Jogador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho);
                Jogador();
                ~Jogador() override;

                void executar() override;
                void deslocar() override;

                void setNaMeleca(bool r_estaNaMeleca);

                bool getAtacando() const;

                void atacar(inimigos::Inimigo *pInimigo);
                void pular();
            };

        }
    }

}




#endif //JOGO_PLAYER_H