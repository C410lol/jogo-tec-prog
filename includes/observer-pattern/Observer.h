#ifndef JOGO_OBSERVER_H
#define JOGO_OBSERVER_H


namespace jogo {
    namespace observers {
        class Observer {
        private:
            int numInscritos;

        public:
            Observer(): numInscritos(0) {}

            virtual ~Observer() = default;

            virtual void update(int message) = 0;

            void operator++() { ++numInscritos; }
            void operator--() { --numInscritos; }
        };
    }
}


#endif //JOGO_OBSERVER_H