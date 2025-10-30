#ifndef JOGO_ENTE_H
#define JOGO_ENTE_H




namespace game {
    namespace managers {
        class GraphicManager;
    }

    class Ente
    {
    protected:
        int id;
        static managers::GraphicManager *pGraphicManager;

    public:
        Ente();
        virtual ~Ente();

        virtual void exec() = 0;

        static void setGraphicManager(managers::GraphicManager *rGraphicManager);
    };

}




#endif //JOGO_ENTE_H