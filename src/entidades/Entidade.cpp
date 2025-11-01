#include "./entidades/Entidade.h"
#include <SFML/Graphics.hpp>




namespace jogo {
    namespace entidades {

        Entidade::Entidade() {}
        Entidade::~Entidade() {}

        void Entidade::mover(const float x, const float y)
        {
            setPosicao(sf::Vector2f(
                getPosicao().x + x, getPosicao().y + y
            ));
        }
        void Entidade::mover(const sf::Vector2f move)
        {
            setPosicao(getPosicao() + move);
        }



        sf::RectangleShape Entidade::getRetangulo() const
        {
            return retangulo;
        }
        sf::Vector2f Entidade::getPosicao() const
        {
            return posicao;
        }
        sf::Vector2f Entidade::getTamanho() const
        {
            return tamanho;
        }

        void Entidade::setPosicao(sf::Vector2f r_posicao)
        {
            posicao = r_posicao;
        }

    }
}
