#pragma once

namespace cdl
{
    struct Offset;
    struct Rect;

    namespace graphics
    {
        struct Image;
    }

    namespace loot
    {
        namespace tab
        {
            struct LootTabCoordinates;

            class LootTabFinder
            {
            public:
                LootTabCoordinates findCoordinates(const graphics::Image& screen) const;
                Offset findHeaderPos(const graphics::Image& screen) const;
                Rect findAreaRect(const graphics::Image& screen) const;
            };
        }
    }
}
