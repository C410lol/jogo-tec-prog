#include "entidades/Projetil.h"

namespace jogo {
    namespace entidades {
        Projetil::Projetil(personagens::Personagem *r_pPersonagem):vel(0.3f), pDono(r_pPersonagem) {
            tamanho=sf::Vector2f(5.0f, 5.0f);
            retangulo.setSize(tamanho);
            retangulo.setFillColor(sf::Color::White);
            sf::Vector2f pos=pDono->getPosicao();
            pos.x+=50;
            setPosicao(pos);
        }
        void Projetil::exec() {
            deslocar();
        }
        void Projetil::deslocar() {
            mover(vel, 0.0f);
            retangulo.setPosition(posicao);
        }
        Projetil::~Projetil() {

        }

    }
}