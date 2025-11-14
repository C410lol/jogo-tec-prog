#include "fases/Fase.h"

#include <iostream>

#include "entidades/obstaculos/Plataforma.h"
#include "entidades/personagens/inimigos/Terrestre.h"
#include "gerenciadores/GerenciadorGrafico.h"




namespace jogo {
    namespace fases {

        Fase::Fase(int r_numJogadores): numJogadores(r_numJogadores) {
            entidades::personagens::Personagem::setFase(this);
            setarProporcao();
        }
        Fase::~Fase() = default;




        void Fase::setarProporcao()
        {
            if (pGerenciadorGrafico)
            {
                proporcao.x = pGerenciadorGrafico->getWindowSize().x / 42.f;
                proporcao.y = pGerenciadorGrafico->getWindowSize().y / 24.f;
            }
        }




        void Fase::criarCenario()
        {
            try
            {
                std::ifstream faseTemplate("../fases-template/primeira-fase.txt");
                std::string linha;

                float x = 0.f;
                float y = 0.f;
                while (std::getline(faseTemplate, linha))
                {
                    for (char c: linha)
                    {
                        criarEntidade(c, x, y);
                        x += proporcao.x;
                    }

                    x = 0.f;
                    y += proporcao.y;
                }
            }
            catch (const std::exception e)
            {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
        }
        void Fase::criarEntidade(char c, float x, float y)
        {
            if (c == 't' || c == '1' || c == 'v' || c == '2' || c == 'b' || c == '3')
                criarInimigos(c, x, y);
            else if (c == 'c' || c == 'p' || c == '4' || c == 'e' || c == '5' || c == 'm' || c == '6')
                criarObstaculos(c, x, y);
            else if (c == 'j')
                criarJogador(sf::Vector2f(x, y), proporcao);
        }





        void Fase::criarJogador(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            if (entidades::personagens::Jogador::instancias >= numJogadores)
                return;

            entidades::personagens::Jogador *pJogador =
                new entidades::personagens::Jogador(posicao, tamanho);
            listaEntidades.incluir(pJogador);
            gerenciadorColisao.incluirJogador(pJogador);
        }




        void Fase::criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::personagens::inimigos::Terrestre *pTerrestre =
                new entidades::personagens::inimigos::Terrestre(posicao, tamanho);

            listaEntidades.incluir(pTerrestre);
            gerenciadorColisao.incluirInimigo(pTerrestre);
        }




        void Fase::criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao)
        {
            entidades::obstaculos::Plataforma *pPlataforma =
                new entidades::obstaculos::Plataforma(posicao, tamanho, false, ehChao);

            listaEntidades.incluir(pPlataforma);
            gerenciadorColisao.incluirObstaculo(pPlataforma);
        }




        void Fase::criarProjetil(entidades::personagens::inimigos::Chefao *pChefao, float velocidade)
        {
            entidades::Projetil *pProjetil =
                new entidades::Projetil
                (
                    pChefao->getPosicao(), proporcao / 2.f, pChefao,
                    velocidade, pChefao->getNivelMaldade()
                );

            listaEntidades.incluir(pProjetil);
            gerenciadorColisao.incluirProjetil(pProjetil);
        }






        void Fase::retirarPersonagem(entidades::personagens::Personagem *pPersonagem)
        {
            if (dynamic_cast<entidades::personagens::Jogador*>(pPersonagem))
            {
                gerenciadorColisao.retirarJogador(
                    dynamic_cast<entidades::personagens::Jogador*>(pPersonagem)
                );

                --entidades::personagens::Jogador::instancias;
                if (entidades::personagens::Jogador::instancias <= 0)
                    pGerenciadorGrafico->fecharJanela();
            }
            else
                gerenciadorColisao.retirarInimigo(
                    dynamic_cast<entidades::personagens::inimigos::Inimigo*>(pPersonagem)
                );

            pPersonagem->setAtivo(false);
        }
        void Fase::retirarProjetil(entidades::Projetil *pProjetil)
        {
            gerenciadorColisao.retirarProjetil(pProjetil);

            pProjetil->setAtivo(false);
        }






        void Fase::inicializar()
        {
            criarCenario();
        }

        void Fase::executar()
        {
            gerenciadorColisao.checarColisoes();
            listaEntidades.executar();
        }

    }
}

