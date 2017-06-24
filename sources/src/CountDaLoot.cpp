#include "CountDaLoot.hpp"

namespace cdl
{
    CountDaLoot::CountDaLoot(int argc, char* argv[])
        : mApplication{ argc, argv }
    {}

    int CountDaLoot::execute()
    {
        mWindow.show();
        return mApplication.exec();
    }
}
