#include "loot/NewLootProvider.hpp"
#include "loot/ILootObserver.hpp"
#include "loot/tab/ILootTabStateObserver.hpp"
#include "graphics/Image.hpp"
#include "loot/LootFilter.hpp"
#include "loot/tab/TabLootReader.hpp"
#include "loot/tab/LootTabData.hpp"

#include <iostream>

namespace cdl
{
    namespace loot
    {
        NewLootProvider::NewLootProvider(log::LoggerFactory& factory)
            : mTabStateLogger{ factory }
            , mLogger{ factory.create() }
        {}

        NewLootProvider::~NewLootProvider()
        {
            stop();
        }

        void NewLootProvider::registerObserver(ILootObserver& observer)
        {
            mObservers.push_back(&observer);
        }

        void NewLootProvider::registerTabStateObserver(tab::ILootTabStateObserver& observer)
        {
            mTabStateObservers.push_back(&observer);
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
                const auto tabData = mLootTabProvider.getTab();

                mTabStateLogger.log("detected tab state: {}", tabData.state);

                for (auto observer : mTabStateObservers)
                    observer->notify(tabData.state);

                if (tabData.tab)
                {
                    const auto lootLines = tab::TabLootReader{}.read(*tabData.tab);
                    const auto newLines = LootFilter{}.filter(mLoot, lootLines);

                    if (!newLines.empty())
                    {
                        mLogger.log("detected new lines:");

                        for(const auto& line : newLines)
                            mLogger.log(line);

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
