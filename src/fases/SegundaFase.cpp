


#include "fases/SegundaFase.h"

#include "entidades/obstaculos/Meleca.h"
#include "entidades/obstaculos/Plataforma.h"
#include "gerenciadores/GerenciadorGrafico.h"

namespace jogo{
    namespace fases{
        SegundaFase::SegundaFase(int r_numJogadores, IDs id):Fase(r_numJogadores), maxTerrestres(8), maxChefoes(7), maxPlataformas(325), maxMelecas(15) {
            Id=id;
            setTexture("../assets/fundos/caverna.png");
            pSprite->setTexture(*pTexture);

            sf::Vector2u windowSize = pGerenciadorGrafico->getJanela()->getSize();
            sf::Vector2u textureSize = pTexture->getSize();
            pSprite->setScale(
                static_cast<float>(windowSize.x) / textureSize.x,
                static_cast<float>(windowSize.y) / textureSize.y
            );
            inicializar();
        }
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
            Fase::criarPlataforma(posicao, tamanho, ehChao, IDs::plataforma_fase2);
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
                criarMelecas(sf::Vector2f(x, y + proporcao.y / 1.25), sf::Vector2f(proporcao.x, proporcao.y / 6));
                break;
            case '5':
                if (rand() % 2)
                    criarMelecas(sf::Vector2f(x, y + proporcao.y / 1.25), sf::Vector2f(proporcao.x, proporcao.y / 6));
                break;
            default:
                break;
            }
        }

    }
}
