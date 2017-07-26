#pragma once

#include "graphics/Image.hpp"
#include "loot/tab/LootTabState.hpp"

#include <boost/optional.hpp>

namespace cdl
{
    namespace loot
    {
        namespace tab
        {
            struct LootTabData
            {
                boost::optional<graphics::Image> tab;
                LootTabState state;
            };
        }
    }
}
