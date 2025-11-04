#ifndef JOGO_ENTE_H
#define JOGO_ENTE_H




namespace jogo {
    namespace gerenciadores {
        class GerenciadorGrafico;
    }

    class Ente
    {
    protected:
        int id;
        static gerenciadores::GerenciadorGrafico *pGerenciadorGrafico;

    public:
        Ente();
        virtual ~Ente();

        virtual void executar() = 0;
        void desenhar();

        static void setGerenciadorGrafico(gerenciadores::GerenciadorGrafico *r_pGerenciadorGrafico);
    };

}




#endif //JOGO_ENTE_H