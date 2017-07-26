#pragma once

#include "utils/string.hpp"

#include <spdlog/spdlog.h>

namespace cdl
{
    namespace log
    {
        class Logger
        {
        public:
            Logger(std::shared_ptr<spdlog::logger> logger)
                : mLogger{ logger }
            {}

            template <typename ...Args>
            void log(const Args&... args)
            {
                mLogger->info(utils::string::toString(args).c_str()...);
                mLogger->flush();
            }

        private:
            std::shared_ptr<spdlog::logger> mLogger;
        };
    }
}
