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
                static int instancias;
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
                Jogador(sf::Vector2f r_posicao, sf::Vector2f r_tamanho);
                Jogador();
                ~Jogador() override;

                void executar() override;

                void salvar() override;

                void setNaMeleca(bool r_estaNaMeleca);
                void setAtacando(bool r_atacando);

                bool getAtacando() const;

                bool getEhPrimeiro() const;

                void atacar(inimigos::Inimigo *pInimigo);

                void pular();
                void moverEsquerda();
                void moverDireita();
                void ataque();
                
                static void setJogadorExiste(bool est);

                static int getInstancias();
                static void setInstancias(int instancias);
            };

        }
    }

}




#endif //JOGO_PLAYER_H