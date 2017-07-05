#pragma once

#include "log/Logger.hpp"
#include "log/ConditionalLogger.hpp"
#include "log/condition/LogDifferentThanLastCondition.hpp"

#include <spdlog/spdlog.h>

namespace cdl
{
    namespace log
    {
        template <typename WrappedType>
        using DifferentThanLastLogger = ConditionalLogger<condition::LogDifferentThanLastCondition<WrappedType>, 
                                                          WrappedType>;
    }
}
