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
            LoggerFactory(const std::string& path)
                : mSink{ std::make_shared<spdlog::sinks::simple_file_sink_mt>(path) }
            {}

            Logger create(const std::string& name = "general")
            {
                return Logger{ std::make_shared<spdlog::logger>(name , mSink) };
            }

        private:
            std::shared_ptr<spdlog::sinks::simple_file_sink_mt> mSink;
        };
    }
}
