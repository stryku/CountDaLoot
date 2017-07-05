#pragma once

#include "log/Logger.hpp"

#include <spdlog/spdlog.h>

namespace cdl
{
    namespace log
    {
        class LoggerFactory
        {
        public:
            LoggerFactory(const std::string& loggerName, const std::string& path)
                : mLogger{ spdlog::basic_logger_mt(loggerName, path) }
            {}

            Logger create()
            {
                return Logger{ mLogger };
            }

        private:
            std::shared_ptr<spdlog::logger> mLogger;
        };
    }
}
