#pragma once

#include "log/Logger.hpp"
#include "log/LoggerFactory.hpp"

#include <vector>

namespace cdl
{
    namespace log
    {
        template <typename Condition, typename LoggingParam>
        class ConditionalLogger
        {
        public:
            ConditionalLogger(LoggerFactory& factory)
                : mLogger{ factory.create() }
            {}

            void log(const std::string& format, const LoggingParam& param)
            {
                if (!mCondition.shouldLog(param))
                    return;

                mCondition.willLogThis(param);
                mLogger.log(format, param);
            }

            void setExternalBool(bool cond)
            {
                mCondition.setExternalBool(cond);
            }

        private:
            Logger mLogger;
            Condition mCondition;
        };
    }
}
