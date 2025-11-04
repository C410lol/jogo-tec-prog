#include "entidades/personagens/inimigos/Inimigo.h"




namespace jogo {
    namespace entidades {
        namespace personagens {
            namespace inimigos {

                Inimigo::Inimigo(Jogador *r_pJogadorAlvo): pJogadorAlvo(r_pJogadorAlvo) {}
                Inimigo::~Inimigo() = default;


                void Inimigo::executar()
                {
                    deslocar();

                    Personagem::executar();
                }

            }
        }
    }
}
