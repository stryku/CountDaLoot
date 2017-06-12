#include "loot/ILootObserver.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

namespace tests
{
    class LootObserverMock : public cdl::loot::ILootObserver
    {
    public:
        MOCK_METHOD1(notify, void(const std::vector<cdl::loot::LootData>&))
    };
}

TEST(Loot, NoObserverCall)
{
    testing::StrictMock<tests::LootObserverMock> observer;
    cdl::TabLootReader reader;
    reader.registerObserver(observer);
}

