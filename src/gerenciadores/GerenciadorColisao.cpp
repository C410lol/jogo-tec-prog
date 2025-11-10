#include "gerenciadores/GerenciadorColisao.h"




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
        }


        void GerenciadorColisao::checarObstaculo_InimigosColisao(
            entidades::obstaculos::Obstaculo *pObstaculo
        )
        {
            if (!pObstaculo)
                return;
            std::vector<entidades::personagens::inimigos::Inimigo*>::iterator itInimigo;
            for (itInimigo=pListaInimigos.begin();
                itInimigo != pListaInimigos.end();
                ++itInimigo)
                {
                    entidades::personagens::inimigos::Inimigo* pInimigo= *itInimigo;
                    if (!pInimigo)
                        continue;
                    if (colidiu(pObstaculo,pInimigo))
                        pObstaculo->colidir(pInimigo);
            }
        }
        void GerenciadorColisao::checarObstaculo_JogadoresColisao(
            entidades::obstaculos::Obstaculo *pObstaculo
        )
        {
            if (pJog1)
            {
                if (colidiu(pObstaculo, pJog1)) {
                    pObstaculo->colidir(pJog1);
                }
            }
        }
        void GerenciadorColisao::checarObstaculoColisoes()
        {

            std::list<entidades::obstaculos::Obstaculo*>::iterator itObstaculo;
            for (
                itObstaculo = pListaObstaculos.begin();
                itObstaculo != pListaObstaculos.end();
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
            if (pJog1)
            {
                if (colidiuVert(pInimigo, pJog1))
                {
                    if (colidiuHor(pInimigo, pJog1))
                        pInimigo->colidir(pJog1);
                    else if
                    (
                        colidiuHor(pInimigo, pJog1, 50)
                        &&
                        (pJog1)->getAtacando()
                    )
                    {
                        float dirX = pInimigo->getPosicao().x - (pJog1)->getPosicao().x;
                        if
                        (
                            dirX < 0 && !(pJog1)->getOlhandoDireita()
                            ||
                            dirX > 0 && (pJog1)->getOlhandoDireita()
                        )
                            (pJog1)->atacar(pInimigo);
                    }
                }
            }
        }
        void GerenciadorColisao::checarInimigoColisoes()
        {

            std::vector<entidades::personagens::inimigos::Inimigo*>::iterator itInimigo;
            for (itInimigo=pListaInimigos.begin();
               itInimigo != pListaInimigos.end();
               ++itInimigo)
            {
                if (!(*itInimigo))
                    continue;

                checarInimigo_JogadoresColisao(*itInimigo);
            }
        }
        void GerenciadorColisao::incluirJogador(entidades::personagens::Jogador *jog) {
            pJog1=jog;
        }
        void GerenciadorColisao::incluirInimigo(entidades::personagens::inimigos::Inimigo *pInimigo) {
            pListaInimigos.push_back(pInimigo);
        }
        entidades::personagens::Jogador* const GerenciadorColisao::getJogador() {
            return pJog1;
        }
        void GerenciadorColisao::incluirObstaculo(entidades::obstaculos::Obstaculo *pObstaculo) {
            pListaObstaculos.push_back(pObstaculo);
        }




    }
}
