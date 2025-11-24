#ifndef JOGO_MENURANKING_H
#define JOGO_MENURANKING_H

#include "menus/Menu.h"
#include "menus/CaixaTexto.h"
#include "dtos/PontuacaoDTO.h"




namespace jogo {
    namespace menus {

        class MenuRanking: public Menu
        {
        private:
            std::vector<CaixaTexto*> caixasTexto;

        public:
            MenuRanking();
            ~MenuRanking();

            void executar() override;
            void atualizar() override;
            void desenhaMenu() override;

            void carregarPontuacoes();
            void ordenarPontuacoes(
                std::ifstream &file, std::vector<dtos::PontuacaoDTO> &pontuacoes
            );
        };

    }
}




#endif //JOGO_MENURANKING_H