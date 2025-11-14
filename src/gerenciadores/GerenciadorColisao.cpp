#include "gerenciadores/GerenciadorColisao.h"

#include <iostream>


namespace jogo {
    namespace gerenciadores {

        GerenciadorColisao::GerenciadorColisao(
        )
        {}
        GerenciadorColisao::~GerenciadorColisao()
        {}




        float GerenciadorColisao::calcOverlapHor(
            entidades::Entidade *ent1,
            entidades::Entidade *ent2,
            float gap
        )
        {
            if (!(ent1 && ent2))
                return 0.f;

            float disX = std::abs(
                            (ent1->getPosicao().x + ent1->getTamanho().x / 2.f) -
                            (ent2->getPosicao().x + ent2->getTamanho().x / 2.f)
            );
            float sumX = (ent1->getTamanho().x / 2.f) + (ent2->getTamanho().x / 2.f);

            if (disX < sumX + gap)
                return sumX - disX;
            return 0;
        }
        float GerenciadorColisao::calcOverlapVert(
            entidades::Entidade *ent1,
            entidades::Entidade *ent2
        )
        {
            float disY = std::abs(
                            (ent1->getPosicao().y + ent1->getTamanho().y / 2.f) -
                            (ent2->getPosicao().y + ent2->getTamanho().y / 2.f)
            );
            float sumY = (ent1->getTamanho().y / 2.f) + (ent2->getTamanho().y / 2.f);

            if (disY < sumY)
                return sumY - disY;
            return 0;
        }
        sf::Vector2f GerenciadorColisao::calcOverlap(
            entidades::Entidade *ent1,
            entidades::Entidade *ent2
        )
        {
            return sf::Vector2f(calcOverlapHor(ent1, ent2), calcOverlapVert(ent1, ent2));
        }



        bool GerenciadorColisao::colidiuHor(
            entidades::Entidade *ent1,
            entidades::Entidade *ent2,
            float gap
        )
        {
            return calcOverlapHor(ent1, ent2, gap) != 0;
        }
        bool GerenciadorColisao::colidiuVert(
            entidades::Entidade *ent1,
            entidades::Entidade *ent2
        )
        {
            return calcOverlapVert(ent1, ent2) != 0;
        }
        bool GerenciadorColisao::colidiu(
            entidades::Entidade *ent1,
            entidades::Entidade *ent2
        )
        {
            return colidiuHor(ent1, ent2) && colidiuVert(ent1, ent2);
        }








        void GerenciadorColisao::checarColisoes()
        {
            checarObstaculoColisoes();
            checarInimigoColisoes();
            checarProjeteisColisoes();
        }




        void GerenciadorColisao::checarObstaculo_InimigosColisao(
            entidades::obstaculos::Obstaculo *pObstaculo
        )
        {
            if (!pObstaculo)
                return;

            std::vector<entidades::personagens::inimigos::Inimigo*>::iterator itInimigo;
            for (itInimigo=listaInimigos.begin();
                itInimigo != listaInimigos.end();
                ++itInimigo)
                {
                    entidades::personagens::inimigos::Inimigo* pInimigo= *itInimigo;
                    if (!pInimigo)
                        continue;
                    if (colidiu(pObstaculo,pInimigo))
                        pObstaculo->obstaculizar(pInimigo);
            }
        }
        void GerenciadorColisao::checarObstaculo_JogadoresColisao(
            entidades::obstaculos::Obstaculo *pObstaculo
        )
        {
            if (!pObstaculo)
                return;

            std::vector<entidades::personagens::Jogador*>::iterator itJogador;
            for
            (
                itJogador = listaJogadores.begin();
                itJogador != listaJogadores.end();
                ++itJogador
            )
            {
                if (!(*itJogador))
                    continue;

                if (colidiu(pObstaculo, *itJogador))
                    pObstaculo->obstaculizar(*itJogador);
            }
        }
        void GerenciadorColisao::checarObstaculo_ProjeteisColisao(entidades::obstaculos::Obstaculo *pObstaculo)
        {
            if (!pObstaculo)
                return;

            std::set<entidades::Projetil*>::iterator itProjetil;
            for
            (
                itProjetil = listaProjeteis.begin();
                itProjetil != listaProjeteis.end();
                ++itProjetil
            )
            {
                if (!(*itProjetil))
                    continue;

                if (colidiu(pObstaculo, *itProjetil)) {
                    (*itProjetil)->destruir();
                }
            }
        }
        void GerenciadorColisao::checarObstaculoColisoes()
        {

            std::list<entidades::obstaculos::Obstaculo*>::iterator itObstaculo;
            for (
                itObstaculo = listaObstaculos.begin();
                itObstaculo != listaObstaculos.end();
                ++itObstaculo
            )
            {
                if (!(*itObstaculo))
                    continue;

                checarObstaculo_InimigosColisao(*itObstaculo);
                checarObstaculo_JogadoresColisao(*itObstaculo);
                checarObstaculo_ProjeteisColisao(*itObstaculo);
            }
        }




        void GerenciadorColisao::checarInimigo_JogadoresColisao(
            entidades::personagens::inimigos::Inimigo *pInimigo
        )
        {
            std::vector<entidades::personagens::Jogador*>::iterator itJogadores;
            for
            (
                itJogadores = listaJogadores.begin();
                itJogadores != listaJogadores.end();
                ++itJogadores
            )
            {
                if (!(*itJogadores))
                    continue;

                if (colidiuVert(pInimigo, *itJogadores))
                {
                    pInimigo->setJogadoralvo(*itJogadores);
                    if (colidiuHor(pInimigo, *itJogadores))
                        pInimigo->danificar(*itJogadores);
                    else if
                    (
                        colidiuHor(pInimigo, *itJogadores, 50)
                        &&
                        (*itJogadores)->getAtacando()
                    )
                    {
                        float dirX = pInimigo->getPosicao().x - (*itJogadores)->getPosicao().x;
                        if
                        (
                            dirX < 0 && !(*itJogadores)->getOlhandoDireita()
                            ||
                            dirX > 0 && (*itJogadores)->getOlhandoDireita()
                        )
                            (*itJogadores)->atacar(pInimigo);
                    }
                }
            }
        }
        void GerenciadorColisao::checarInimigoColisoes()
        {

            std::vector<entidades::personagens::inimigos::Inimigo*>::iterator itInimigo;
            for
            (
                itInimigo=listaInimigos.begin();
                itInimigo != listaInimigos.end();
                ++itInimigo)
            {
                if (!(*itInimigo))
                    continue;

                checarInimigo_JogadoresColisao(*itInimigo);
            }
        }




        void GerenciadorColisao::checarProjeteis_JogadoresColisao(entidades::Projetil *pProjetil)
        {
            std::vector<entidades::personagens::Jogador*>::iterator itJogador;
            for
            (
                itJogador = listaJogadores.begin();
                itJogador != listaJogadores.end();
                ++itJogador
            )
            {
                if (!(*itJogador))
                    continue;

                if (colidiu(pProjetil, *itJogador))
                    pProjetil->acertar(*itJogador);
            }
        }
        void GerenciadorColisao::checarProjeteisColisoes()
        {
            std::set<entidades::Projetil*>::iterator itProjetil;
            for
            (
                itProjetil = listaProjeteis.begin();
                itProjetil != listaProjeteis.end();
                ++itProjetil
            )
            {
                if (!(*itProjetil))
                    continue;

                checarProjeteis_JogadoresColisao(*itProjetil);
            }
        }





        void GerenciadorColisao::incluirJogador(entidades::personagens::Jogador *jog)
        {
            listaJogadores.push_back(jog);
        }
        void GerenciadorColisao::incluirInimigo(entidades::personagens::inimigos::Inimigo *pInimigo)
        {
            listaInimigos.push_back(pInimigo);
        }
        void GerenciadorColisao::incluirObstaculo(entidades::obstaculos::Obstaculo *pObstaculo)
        {
            listaObstaculos.push_back(pObstaculo);
        }
        void GerenciadorColisao::incluirProjetil(entidades::Projetil *pProjetil)
        {
            listaProjeteis.insert(pProjetil);
        }




        void GerenciadorColisao::retirarJogador(entidades::personagens::Jogador *pJogador)
        {
            std::vector<entidades::personagens::Jogador*>::iterator itJogador;
            for
            (
                itJogador = listaJogadores.begin();
                itJogador != listaJogadores.end();
                ++itJogador
            )
            {
                if (!(*itJogador))
                    continue;

                if (*itJogador == pJogador)
                {
                    listaJogadores.erase(itJogador);
                    break;
                }
            }
        }
        void GerenciadorColisao::retirarInimigo(entidades::personagens::inimigos::Inimigo *pInimigo)
        {
            std::vector<entidades::personagens::inimigos::Inimigo*>::iterator itInimigo;
            for
            (
                itInimigo = listaInimigos.begin();
                itInimigo != listaInimigos.end();
                ++itInimigo
            )
            {
                if (!(*itInimigo))
                    continue;

                if (*itInimigo == pInimigo)
                {
                    listaInimigos.erase(itInimigo);
                    break;
                }
            }
        }
        void GerenciadorColisao::retirarProjetil(entidades::Projetil *pProjetil)
        {
            std::set<entidades::Projetil*>::iterator itProjetil;
            for
            (
                itProjetil = listaProjeteis.begin();
                itProjetil != listaProjeteis.end();
                ++itProjetil
            )
            {
                if (!(*itProjetil))
                    continue;

                if (*itProjetil == pProjetil)
                {
                    listaProjeteis.erase(itProjetil);
                    break;
                }
            }
        }

    }
}
