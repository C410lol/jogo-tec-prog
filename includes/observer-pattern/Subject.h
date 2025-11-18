#ifndef JOGO_SUBJECT_H
#define JOGO_SUBJECT_H

#include <list>
#include "observer-pattern/Observer.h"




namespace jogo {
    namespace observers {

        class Subject
        {
        private:
            std::list<Observer*> observers;

        public:
            Subject() = default;
            virtual ~Subject() = default;

            void attach(Observer* observer)
            {
                observers.push_back(observer);
            }
            void detach(Observer* observer)
            {
                std::list<Observer*>::iterator itObserver;
                for (itObserver = observers.begin(); itObserver != observers.end(); ++itObserver)
                {
                    if (*itObserver)
                    {
                        if (*itObserver == observer)
                        {
                            observers.erase(itObserver);
                            break;
                        }
                    }
                }
            }

            void notify(int message)
            {
                std::list<Observer*>::iterator itObserver;
                for (itObserver = observers.begin(); itObserver != observers.end(); ++itObserver)
                    if (*itObserver)
                        (*itObserver)->update(message);
            }
        };

    }
}



#endif //JOGO_SUBJECT_H