#pragma once

#include "loot/tab/LootTabProvider.hpp"
#include "thread/ThreadWorker.hpp"

#include <vector>

namespace cdl
{
    namespace loot
    {
        class ILootObserver;

        namespace tab
        {
            class ILootTabStateObserver;
        }

        class NewLootProvider
        {
        public:
            ~NewLootProvider();
            void registerObserver(ILootObserver& observer);
            void registerTabStateObserver(tab::ILootTabStateObserver& observer);
            void start();
            void stop();

        private:
            static const size_t kSleep = static_cast<size_t>(1000);

            std::function<void()> getCallback();

            std::vector<ILootObserver*> mObservers;
            std::vector<tab::ILootTabStateObserver*> mTabStateObservers;
            thread::ThreadWorker mThreadWorker;
            tab::LootTabProvider mLootTabProvider;
            std::vector<std::string> mLoot;
        };
    }
}
