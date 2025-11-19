#include "fases/PrimeiraFase.h"

#include <iostream>

#include "entidades/obstaculos/Plataforma.h"
#include "entidades/obstaculos/Espinho.h"
#include "entidades/personagens/inimigos/Terrestre.h"
#include "entidades/personagens/inimigos/Voador.h"
#include "gerenciadores/GerenciadorGrafico.h"


namespace jogo {
    namespace fases {

        PrimeiraFase::PrimeiraFase(int r_numJogadores, IDs id):
        Fase(r_numJogadores), maxTerrestres(8), maxVoadores(4), maxPlataformas(315), maxEspinhos(20) {
            Id=id;
            setTexture("../assets/fundos/planicie.png");
            pSprite->setTexture(*pTexture);

            sf::Vector2u windowSize = pGerenciadorGrafico->getJanela()->getSize();
            sf::Vector2u textureSize = pTexture->getSize();
            pSprite->setScale(
                static_cast<float>(windowSize.x) / textureSize.x,
                static_cast<float>(windowSize.y) / textureSize.y
            );
            inicializar();
        }
        PrimeiraFase::~PrimeiraFase() {

        }




        void PrimeiraFase::criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (entidades::personagens::inimigos::Terrestre::getInstancias() >= maxTerrestres)
                return;
            Fase::criarTerrestre(posicao, tamanho);
        }
        void PrimeiraFase::criarVoador(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (entidades::personagens::inimigos::Voador::getInstancias() >= maxVoadores)
                return;

            entidades::personagens::inimigos::Voador *pVoador =
                new entidades::personagens::inimigos::Voador(posicao, tamanho);

            listaEntidades.incluir(pVoador);
            gerenciadorColisao.incluirInimigo(pVoador);
        }




        void PrimeiraFase::criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao)
        {
            if (entidades::obstaculos::Plataforma::getInstancias() >= maxPlataformas)
                return;
            Fase::criarPlataforma(posicao, tamanho, ehChao, IDs::plataforma_fase1);
        }
        void PrimeiraFase::criarEspinho(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (entidades::obstaculos::Espinho::getInstancias() >= maxEspinhos)
                return;

            entidades::obstaculos::Espinho *pEspinho =
                new entidades::obstaculos::Espinho(posicao, tamanho, true, 1);

            listaEntidades.incluir(pEspinho);
            gerenciadorColisao.incluirObstaculo(pEspinho);
        }




        void PrimeiraFase::criarInimigos(char c, float x, float y)
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
                    criarVoador(sf::Vector2f(x, y), proporcao);
                    break;
                case '2':
                    if (rand() % 2)
                        criarVoador(sf::Vector2f(x, y), proporcao);
                    break;
                default:
                    break;
            }
        }
        void PrimeiraFase::criarObstaculos(char c, float x, float y)
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
                    criarEspinho(sf::Vector2f(x, y + proporcao.y / 2), sf::Vector2f(proporcao.x, proporcao.y / 2));
                    break;
                case '5':
                    if (rand() % 2)
                        criarEspinho(sf::Vector2f(x, y + proporcao.y / 2), sf::Vector2f(proporcao.x, proporcao.y / 2));
                    break;
                default:
                    break;
            }
        }

    }
}
