#pragma once

#include <vector>

namespace cdl
{
    namespace log
    {
        template <typename Condition, typename Logger, typename ...LogArgs>
        class ConditionalLogger
        {
        public:
            ConditionalLogger(const std::string& loggerName, const std::string& path)
                : logger{ loggerName, path }
            {}

            void log(const LogArgs& ...logArgs)
            {
                if (!condition.shouldLog(logArgs...))
                    return;

                condition.willLogThis(logArgs...);
                logger.log(logArgs...);
            }

            void setExternalBool(bool cond)
            {
                condition.setExternalBool(cond);
            }

        private:
            Logger logger;
            Condition condition;
        };
    }
}
