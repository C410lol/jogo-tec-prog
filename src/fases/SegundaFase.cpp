


#include "fases/SegundaFase.h"

#include "entidades/obstaculos/Meleca.h"
#include "entidades/obstaculos/Plataforma.h"

namespace jogo{
    namespace fases{
        SegundaFase::SegundaFase(int r_numJogadores):Fase(r_numJogadores), maxTerrestres(8), maxChefoes(4), maxPlataformas(325), maxMelecas(15)
        {}
        SegundaFase::~SegundaFase() = default;

        void SegundaFase::criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (entidades::personagens::inimigos::Terrestre::instancias >= maxTerrestres)
                return;
            Fase::criarTerrestre(posicao, tamanho);
        }
        void SegundaFase::criarChefoes(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (entidades::personagens::inimigos::Chefao::getInstancias()>= maxChefoes)
                return;
            entidades::personagens::inimigos::Chefao *pChefao =
                    new entidades::personagens::inimigos::Chefao(posicao, tamanho);
            listaEntidades.incluir(pChefao);
            gerenciadorColisao.incluirInimigo(pChefao);
        }
        void SegundaFase::criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao)
        {
            if (entidades::obstaculos::Plataforma::instancias >= maxPlataformas)
                return;
            Fase::criarPlataforma(posicao, tamanho, ehChao);
        }
        void SegundaFase::criarMelecas(sf::Vector2f r_posicao, sf::Vector2f r_tamanho)
        {
            if (entidades::obstaculos::Meleca::instancias>= maxMelecas)
                return;
            entidades::obstaculos::Meleca *pMeleca =
                new entidades::obstaculos::Meleca(r_posicao, r_tamanho, false, 1);
            listaEntidades.incluir((pMeleca));
            gerenciadorColisao.incluirObstaculo(pMeleca);
        }
        void SegundaFase::criarInimigos(char c, float x, float y)
        {
            switch (c)
            {
            case 't':
                criarTerrestre(sf::Vector2f(x, y), proporcao);
                break;
            case '1':
                if (rand() % 2)
                    criarTerrestre(sf::Vector2f(x, y), proporcao);
                break;
            case 'v':
                criarChefoes(sf::Vector2f(x, y), proporcao);
                break;
            case '2':
                if (rand() % 2)
                    criarChefoes(sf::Vector2f(x, y), proporcao);
                break;
            default:
                break;
            }
        }
        void SegundaFase::criarObstaculos(char c, float x, float y)
        {
            switch (c)
            {
            case 'c':
                criarPlataforma(sf::Vector2f(x, y), proporcao, true);
                break;
            case 'p':
                criarPlataforma(sf::Vector2f(x, y), proporcao, false);
                break;
            case '4':
                if (rand() % 2)
                    criarPlataforma(sf::Vector2f(x, y), proporcao, false);
                break;
            case 'e':
                criarMelecas(sf::Vector2f(x, y + proporcao.y / 2), sf::Vector2f(proporcao.x, proporcao.y / 2));
                break;
            case '5':
                if (rand() % 2)
                    criarMelecas(sf::Vector2f(x, y + proporcao.y / 2), sf::Vector2f(proporcao.x, proporcao.y / 2));
                break;
            default:
                break;
            }
        }







    }
}
