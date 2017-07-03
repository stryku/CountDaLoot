#pragma once

#include "log/converter/SimpleToStringConverter.hpp"

#include <spdlog/spdlog.h>

namespace cdl
{
    namespace log
    {
        template <typename ToStringConverter = converter::SimpleToStringConverter>
        class Logger
        {
        public:
            Logger(const std::string& loggerName, const std::string& path)
                : logger{ spdlog::basic_logger_mt(loggerName, path) }
            {}

            template <typename ...Args>
            void log(const Args&... args)
            {
                logger->info(ToStringConverter::convert(std::forward<Args>(args)...));
                logger->flush();
            }

        private:
            std::shared_ptr<spdlog::logger> logger;
        };
    }
}
