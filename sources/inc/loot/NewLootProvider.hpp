#pragma once

#include "loot/tab/LootTabProvider.hpp"
#include "thread/ThreadWorker.hpp"

#include <vector>

namespace cdl
{
    namespace loot
    {
        class ILootObserver;

        class NewLootProvider
        {
        public:
            ~NewLootProvider();
            void registerObserver(ILootObserver& observer);
            void start();
            void stop();

        private:
            static const size_t kSleep = static_cast<size_t>(100);

            std::function<void()> getCallback();

            std::vector<ILootObserver*> mObservers;
            thread::ThreadWorker mThreadWorker;
            tab::LootTabProvider mLootTabProvider;
            std::vector<std::string> mLoot;
        };
    }
}
