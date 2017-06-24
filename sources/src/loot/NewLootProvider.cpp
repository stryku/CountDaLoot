#include "loot/NewLootProvider.hpp"
#include "loot/ILootObserver.hpp"
#include "graphics/Image.hpp"
#include "loot/LootFilter.hpp"
#include "loot/tab/TabLootReader.hpp"

#include <iostream>

namespace cdl
{
    namespace loot
    {
        void NewLootProvider::registerObserver(ILootObserver& observer)
        {
            mObservers.push_back(&observer);
        }

        void NewLootProvider::start()
        {
            mThreadWorker.start(getCallback(), std::chrono::milliseconds{ kSleep });
        }

        void NewLootProvider::stop()
        {
            mThreadWorker.stop();
        }

        std::function<void()> NewLootProvider::getCallback()
        {
            return [this]
            {
                const auto tab = mLootTabProvider.getTab();

                if (tab)
                {
                    const auto lootLines = tab::TabLootReader{}.read(*tab);
                    const auto newLines = LootFilter{}.filter(mLoot, lootLines);

                    if (!newLines.empty())
                    {
                        for (auto observer : mObservers)
                            observer->notify(newLines);

                        mLoot.insert(std::end(mLoot),
                                     std::cbegin(newLines), std::cend(newLines));
                    }
                }
            };
        }
    }
}
