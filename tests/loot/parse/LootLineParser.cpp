#include "loot/parse/LootLineParser.hpp"
#include "loot/parse/ParsedLootLine.hpp"

#include <gtest/gtest.h>

namespace tests
{
    namespace loot
    {
        namespace parse
        {
            namespace a_and_an
            {
                struct LootLineParserTestStruct
                {
                    const std::string line;
                    const std::string expectedMonster;
                };

                struct LootLineParserTest : testing::Test, testing::WithParamInterface<LootLineParserTestStruct> {};

                TEST_P(LootLineParserTest, aAndAnMonster)
                {
                    const auto param = GetParam();
                    const auto result = cdl::loot::parse::LootLineParser{}.parse(param.line);
                    ASSERT_EQ(result.monster, param.expectedMonster);
                }

                INSTANTIATE_TEST_CASE_P(LootLineParser, LootLineParserTest,
                                        testing::Values(
                                        LootLineParserTestStruct{
                                            std::string{ "Loot of a monster: " },
                                            std::string{ "monster" }
                                        },
                                        LootLineParserTestStruct{
                                            std::string{ "Loot of an monster: " },
                                            std::string{ "monster" }
                                        }));
            }

            namespace monster_name
            {
                struct MonsterNameTestStruct
                {
                    const std::string line;
                    const std::string expectedMonsterName;
                };

                struct MonsterNameTest : testing::Test, testing::WithParamInterface<MonsterNameTestStruct> {};

                TEST_P(MonsterNameTest, MonsterName)
                {
                    const auto param = GetParam();
                    const auto result = cdl::loot::parse::LootLineParser{}.parse(param.line);
                    ASSERT_EQ(result.monster, param.expectedMonsterName);
                }

                INSTANTIATE_TEST_CASE_P(LootLineParser, MonsterNameTest,
                                        testing::Values(
                                        MonsterNameTestStruct{
                                            std::string{ "Loot of a monster: " },
                                            std::string{ "monster" }
                                        },
                                        MonsterNameTestStruct{
                                            std::string{ "Loot of an Long Monster Name: " },
                                            std::string{ "Long Monster Name" }
                                        },
                                        MonsterNameTestStruct{
                                            std::string{ "Loot of an Monster'something: " },
                                            std::string{ "Monster'something" }
                                        }));
            }
        }
    }
}
