#pragma once

#include "log/Logger.hpp"
#include "log/converter/RectToStringConverter.hpp"
#include "log/converter/PosToStringConverter.hpp"
#include "log/converter/RgbaToStringConverter.hpp"
#include "log/converter/SizeToStringConverter.hpp"

namespace cdl
{
    namespace log
    {
        class StructLogger
        {
        public:
            StructLogger(const std::string& loggerName, const std::string& path)
                : logger{ spdlog::basic_logger_mt(loggerName, path) }
            {}

            template <typename ...Args>
            void log(const Args&... args)
            {
                const auto toLog = formatArgs(args...);
                logger->info(toLog);
                logger->flush();
            }

        private:
            template <typename ...Args>
            std::string formatArgs(const Args&... args)
            {
                std::string ret;

                const auto formatted = { format(args)... };

                for (const auto& part : formatted)
                    ret += part;

                return ret;
            }

            std::string format(const std::string& str) const
            {
                return str;
            }

            std::string format(const Rect& rect) const
            {
                return convert::RectToStringConverter{}.convert(rect);
            }

            std::string format(const Size& size) const
            {
                return convert::SizeToStringConverter{}.convert(size);
            }

            std::string format(const Rgba& rgba) const
            {
                return convert::RgbaToStringConverter{}.convert(rgba);
            }

            template <typename PosField>
            std::string format(const details::PosImpl<PosField>& pos) const
            {
                return convert::PosToStringConverter{}.convert(pos);
            }

            std::shared_ptr<spdlog::logger> logger;
        };
    }
}
