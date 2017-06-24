#pragma once

#include <thread>
#include <chrono>

namespace cdl
{
    namespace thread
    {
        class ThreadWorker
        {
        public:
            ~ThreadWorker();

            template <typename LoopFunction, typename Duration>
            void start(LoopFunction loopFunction, const Duration& sleepDuration)
            {
                stop();

                auto loop = [this, loopFunction, sleepDuration]()
                {
                    while (needRunning)
                    {
                        const auto sleepTo = std::chrono::system_clock::now() +
                                             sleepDuration;

                        loopFunction();

                        std::this_thread::sleep_until(sleepTo);
                    }
                };

                needRunning = true;

                thread = std::thread{ loop };
            }

            template <typename LoopFunction>
            void startSingleCall(LoopFunction loopFunction)
            {
                stop();

                auto fun = [this, loopFunction]()
                {
                    loopFunction();
                };

                needRunning = true;

                thread = std::thread{ fun };
            }

            void stop();

        private:
            std::thread thread;
            bool needRunning{ false };
        };
    }
}
