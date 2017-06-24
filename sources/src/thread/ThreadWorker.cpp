#include "thread/ThreadWorker.hpp"

namespace cdl
{
    namespace thread
    {
        ThreadWorker::~ThreadWorker()
        {
            stop();
        }

        void ThreadWorker::stop()
        {
            if (needRunning)
            {
                needRunning = false;

                if (thread.joinable())
                    thread.join();
            }
        }
    }
}
