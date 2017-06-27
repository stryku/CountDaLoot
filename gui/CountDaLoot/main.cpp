#include "CountDaLoot.hpp"

#include "loot/parse/LootLineParser.hpp"
#include "loot/parse/ParsedLootLine.hpp"

int main(int argc, char *argv[])
{
    cdl::CountDaLoot countDaLoot{ argc, argv };
    return countDaLoot.execute();
}
