#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>

namespace tests
{
    class LootObserverMock : public cdl::ILootObserver
    {
    public:
        MOCK_METHOD1(notify, void(std::vector<Loot>))
    };
}

TEST(Loot, NoObserverCall)
{
    testing::StrictMock<tests::LootObserverMock> observer;
    cdl::TabLootReader reader;
    reader.registerObserver(observer);
}

