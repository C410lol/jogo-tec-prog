#include "./entidades/personagens/Personagem.h"




namespace jogo {
    namespace entidades {
        namespace personagens {

            Personagem::Personagem(): vidas(3) {};
            Personagem::~Personagem() = default;

            void Personagem::exec()
            {
                retangulo.setPosition(posicao);
            }

            void Personagem::cair()
            {
                posicao.y += GRAVIDADE;
            }

        }
    }
}
