#include "fases/Fase.h"

#include <iostream>
#include <fstream>

#include "entidades/obstaculos/Espinho.h"
#include "entidades/obstaculos/Meleca.h"
#include "entidades/obstaculos/Plataforma.h"
#include "entidades/personagens/inimigos/Terrestre.h"
#include "entidades/personagens/inimigos/Voador.h"
#include "fases/PrimeiraFase.h"
#include "gerenciadores/GerenciadorGrafico.h"
#include "observer-pattern/input/InputSubject.h"




namespace jogo {
    namespace fases {

        Fase::Fase(int r_numJogadores): numJogadores(r_numJogadores) {
            jogo::entidades::personagens::inimigos::Terrestre::instancias = 0;
            jogo::entidades::personagens::inimigos::Voador::instancias = 0;
            jogo::entidades::personagens::inimigos::Chefao::setInstancias(0);
            entidades::personagens::Jogador::instancias = 0;
            entidades::obstaculos::Plataforma::instancias = 0;
            entidades::obstaculos::Meleca::instancias = 0;
            entidades::obstaculos::Espinho::instancias = 0;
            entidades::personagens::Jogador::setJogadorExiste(false);


            entidades::personagens::Personagem::setFase(this);
            setarProporcao();
        }
        Fase::~Fase() {
            for (auto it = listaEntidades.begin(); it != listaEntidades.end(); ++it) {
                delete *it;
            }
            listaEntidades.limpar();
        }




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
                std::ifstream faseTemplate;
                if (dynamic_cast<fases::PrimeiraFase*>(this))
                    faseTemplate.open("../fases-template/primeira-fase.txt");
                else
                    faseTemplate.open("../fases-template/segunda-fase.txt");

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
            observers::JogadorObserver *pJogadorObserver =
                new observers::JogadorObserver(pJogador);

            listaEntidades.incluir(pJogador);
            gerenciadorColisao.incluirJogador(pJogador);

            observers::InputSubject::getInstancia()->attach(pJogadorObserver);
            jogadorObservers.push_back(pJogadorObserver);
        }




        void Fase::criarTerrestre(sf::Vector2f posicao, sf::Vector2f tamanho)
        {
            entidades::personagens::inimigos::Terrestre *pTerrestre =
                new entidades::personagens::inimigos::Terrestre(posicao, tamanho);

            listaEntidades.incluir(pTerrestre);
            gerenciadorColisao.incluirInimigo(pTerrestre);
        }




        void Fase::criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, bool ehChao, IDs id)
        {
            entidades::obstaculos::Plataforma *pPlataforma =
                new entidades::obstaculos::Plataforma(posicao, tamanho, false, ehChao, id);

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
            entidades::personagens::Jogador *pJogador =
                dynamic_cast<entidades::personagens::Jogador*>(pPersonagem);
            if (pJogador)
            {
                gerenciadorColisao.retirarJogador(pJogador);
                retirarJogadorObserver(pJogador);

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
        void Fase::retirarJogadorObserver(entidades::personagens::Jogador *pJogador)
        {
            std::vector<observers::JogadorObserver*>::iterator itJogadorObserver;
            for
            (
                itJogadorObserver = jogadorObservers.begin();
                itJogadorObserver != jogadorObservers.end();
                ++itJogadorObserver
            )
            {
                if (*itJogadorObserver)
                {
                    if ((*itJogadorObserver)->getJogador() == pJogador)
                    {
                        observers::InputSubject::getInstancia()->detach(*itJogadorObserver);
                        delete *itJogadorObserver;
                        jogadorObservers.erase(itJogadorObserver);
                        break;
                    }
                }
            }
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
            pGerenciadorGrafico->desenhar(*pSprite);
            listaEntidades.executar();
            gerenciadorColisao.checarColisoes();
        }

    }
}

