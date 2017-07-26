#pragma once

#include "graphics/Image.hpp"

#include <boost/optional.hpp>

namespace cdl
{
    struct Rect;

    namespace loot
    {
        namespace tab
        {
            struct LootTabCoordinates;

            class LootTabFinder
            {
            public:
                explicit LootTabFinder();

                boost::optional<LootTabCoordinates> findCoordinates(const graphics::Image& screen) const;
                boost::optional<Offset> findHeaderPos(const graphics::Image& screen) const;
                boost::optional<Rect> findAreaRect(const graphics::Image& screen, const Offset& tabHeaderOffset) const;

            private:
                boost::optional<Rect> findInputFieldRect(const graphics::Image& screen) const;
                boost::optional<Offset> findEndOfInputField(const graphics::Image& screen, const Offset& patternPos) const;
                boost::optional<Offset> findBeginOfInputField(const graphics::Image& screen, const Offset& patternPos) const;
                boost::optional<Offset> findUpArrowPos(const graphics::Image& screen, const Rect& inputFieldRect) const;
                Rect findAreaRect(const Rect& inputFieldRect, const Offset& upArrowPos) const;

                const graphics::Image mLootActivePattern;
                const graphics::Image mLootInactivePattern;
                const graphics::Image mLootInactiveRedPattern;
                const graphics::Image mInputFieldPattern;
                const graphics::Image mUparrowPattern;
            };
        }
    }
}
