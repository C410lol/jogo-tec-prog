#include "gerenciadores/GerenciadorColisao.h"




namespace jogo {
    namespace gerenciadores {

        GerenciadorColisao::GerenciadorColisao(
            listas::Lista<entidades::personagens::Jogador*> *r_pListaJogadores,
            listas::Lista<entidades::personagens::inimigos::Inimigo*> *r_pListaInimigos,
            listas::Lista<entidades::obstaculos::Obstaculo*> *r_pListaObstaculos
        ):
        pListaJogadores(r_pListaJogadores),
        pListaInimigos(r_pListaInimigos),
        pListaObstaculos(r_pListaObstaculos)
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
        }


        void GerenciadorColisao::checarObstaculo_InimigosColisao(
            entidades::obstaculos::Obstaculo *pObstaculo
        )
        {
            if (pListaInimigos)
            {
                listas::Lista<entidades::personagens::inimigos::Inimigo*>::Iterator itInimigo;
                for (
                itInimigo = pListaInimigos->begin();
                itInimigo != pListaInimigos->end();
                ++itInimigo
                )
                {
                    if (!(*itInimigo))
                        continue;

                    if (colidiu(pObstaculo, *itInimigo))
                        pObstaculo->colidir(*itInimigo);
                }
            }
        }
        void GerenciadorColisao::checarObstaculo_JogadoresColisao(
            entidades::obstaculos::Obstaculo *pObstaculo
        )
        {
            if (pListaJogadores)
            {
                listas::Lista<entidades::personagens::Jogador*>::Iterator itJogador;
                for (
                itJogador = pListaJogadores->begin();
                itJogador != pListaJogadores->end();
                ++itJogador
                )
                {
                    if (!(*itJogador))
                        continue;

                    if (colidiu(pObstaculo, *itJogador))
                        pObstaculo->colidir(*itJogador);
                }
            }
        }
        void GerenciadorColisao::checarObstaculoColisoes()
        {
            if (!pListaObstaculos)
                return;

            listas::Lista<entidades::obstaculos::Obstaculo*>::Iterator itObstaculo;
            for (
                itObstaculo = pListaObstaculos->begin();
                itObstaculo != pListaObstaculos->end();
                ++itObstaculo
            )
            {
                if (!(*itObstaculo))
                    continue;

                checarObstaculo_InimigosColisao(*itObstaculo);
                checarObstaculo_JogadoresColisao(*itObstaculo);
            }
        }


        void GerenciadorColisao::checarInimigo_JogadoresColisao(
            entidades::personagens::inimigos::Inimigo *pInimigo
        )
        {
            if (pListaJogadores)
            {
                listas::Lista<entidades::personagens::Jogador*>::Iterator itJogador;
                for (
                    itJogador = pListaJogadores->begin();
                    itJogador != pListaJogadores->end();
                    ++itJogador
                )
                {
                    if (!(*itJogador))
                        continue;

                    if (colidiuVert(pInimigo, *itJogador))
                    {
                        if (colidiuHor(pInimigo, *itJogador))
                            pInimigo->colidir(*itJogador);
                        else if
                        (
                            colidiuHor(pInimigo, *itJogador, 50)
                            &&
                            (*itJogador)->getAtacando()
                        )
                        {
                            float dirX = pInimigo->getPosicao().x - (*itJogador)->getPosicao().x;
                            if
                            (
                                dirX < 0 && !(*itJogador)->getOlhandoDireita()
                                ||
                                dirX > 0 && (*itJogador)->getOlhandoDireita()
                            )
                                (*itJogador)->atacar(pInimigo);
                        }
                    }
                }
            }
        }
        void GerenciadorColisao::checarInimigoColisoes()
        {
            if (!pListaInimigos)
                return;

            listas::Lista<entidades::personagens::inimigos::Inimigo*>::Iterator itInimigo;
            for (
                itInimigo = pListaInimigos->begin();
                itInimigo != pListaInimigos->end();
                ++itInimigo
            )
            {
                if (!(*itInimigo))
                    continue;

                checarInimigo_JogadoresColisao(*itInimigo);
            }
        }

    }
}
