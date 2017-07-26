#include "CountDaLoot.hpp"

int main(int argc, char *argv[])
{
    cdl::CountDaLoot countDaLoot{ argc, argv };
    return countDaLoot.execute();
}
