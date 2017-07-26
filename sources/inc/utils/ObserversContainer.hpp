#pragma once

#include <vector>

namespace cdl
{
    namespace utils
    {
        template <typename Observer>
        class ObserversContainer
        {
        public:
            void registerObserver(Observer& observer)
            {
                mObservers.push_back(&observer);
            }

            template <typename ...Args>
            void notify(Args&... args)
            {
                for (auto& observer : mObservers)
                    observer->notify(std::forward<Args>(args)...);
            }

        private:
            std::vector<Observer*> mObservers;
        };
    }
}
