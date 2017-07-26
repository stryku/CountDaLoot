#pragma once

#include "structs/Pos.hpp"
#include "structs/Rect.hpp"

namespace cdl
{
    namespace loot
    {
        namespace tab
        {
            struct LootTabCoordinates
            {
                Offset tabHeaderPos;
                Rect tabArea;
            };
        }
    }
}
