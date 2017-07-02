#include "loot/parse/LootLineParser.hpp"
#include "loot/parse/ParsedLootLine.hpp"

#include <gtest/gtest.h>

namespace tests
{
    namespace loot
    {
        namespace parse
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
    }

}
