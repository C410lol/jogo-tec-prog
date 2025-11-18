#ifndef JOGO_OBSERVER_H
#define JOGO_OBSERVER_H



namespace jogo {
    namespace observers {

        class Observer
        {
        public:
            Observer() = default;
            virtual ~Observer() = default;

            virtual void update(int message) = 0;
        };

    }
}



#endif //JOGO_OBSERVER_H