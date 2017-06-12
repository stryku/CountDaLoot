#include "loot/ILootObserver.hpp"
#include "loot/TabLootReader.hpp"
#include "loot/LootData.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

namespace tests
{
    class LootObserverMock : public cdl::loot::ILootObserver
    {
    public:
        MOCK_METHOD1(notify, void(const std::vector<cdl::loot::LootData>&));
    };
}

TEST(Loot, NOP_NoObserverCall)
{
    testing::StrictMock<tests::LootObserverMock> observer;
    cdl::loot::TabLootReader reader;
    reader.registerObserver(observer);
}

