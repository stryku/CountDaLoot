#pragma once

#include "graphics/Image.hpp"

#include <boost/optional.hpp>

namespace cdl
{
    namespace loot
    {
        class LootTabProvider
        {
        public:
            boost::optional<graphics::Image> getTab();
        };
    }
}
