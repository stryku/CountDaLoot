#include "loot/tab/LootTabFinder.hpp"

#include "data/img/ImageDataProvider.hpp"
#include "graphics/Image.hpp"
#include "loot/tab/LootTabCoordinates.hpp"
#include "structs/Pos.hpp"
#include "structs/Rect.hpp"


namespace cdl
{
    namespace loot
    {
        namespace tab
        {
            LootTabFinder::LootTabFinder()
                : mLootActivePattern(data::img::ImageDataProvider{}.getLootTabActive())
                , mLootInactivePattern(data::img::ImageDataProvider{}.getLootTabInactive())
                , mLootInactiveRedPattern(data::img::ImageDataProvider{}.getLootTabInactiveRed())
                , mInputFieldPattern(data::img::ImageDataProvider{}.getInputFieldPattern())
                , mUparrowPattern(data::img::ImageDataProvider{}.getUpArrowPattern())
            {}

            boost::optional<LootTabCoordinates> LootTabFinder::findCoordinates(const graphics::Image& screen) const
            {
                const auto headerPos{ findHeaderPos(screen) };

                if (!headerPos)
                    return{};

                const auto areaRect{ findAreaRect(screen, *headerPos) };

                if (!areaRect)
                    return{};

                return LootTabCoordinates{ *headerPos, *areaRect };
            }

            boost::optional<Offset> LootTabFinder::findHeaderPos(const graphics::Image& screen) const
            {
                return screen.findOneOf({ mLootActivePattern,
                                          mLootInactivePattern,
                                          mLootInactiveRedPattern });
            }

            boost::optional<Rect> LootTabFinder::findAreaRect(const graphics::Image& screen, const Offset& tabHeaderOffset) const
            {
                const auto inputFieldRect{ findInputFieldRect(screen) };

                if (!inputFieldRect)
                    return{};

                const auto upArrowPos{ findUpArrowPos(screen, *inputFieldRect) };

                if (!upArrowPos)
                    return{};

                return findAreaRect(*inputFieldRect, *upArrowPos);
            }

            boost::optional<Offset> LootTabFinder::findEndOfInputField(const graphics::Image& screen, const Offset& patternPos) const
            {
                const auto inputFieldPatternPixel = mInputFieldPattern.cpixel(0, 0);

                for (size_t x = patternPos.x; x < screen.w; ++x)
                    if (screen.cpixel(x, patternPos.y) != inputFieldPatternPixel)
                        return Offset{ x, patternPos.y };

                return {};
            }

            boost::optional<Offset> LootTabFinder::findBeginOfInputField(const graphics::Image& screen, const Offset& patternPos) const
            {
                const auto inputFieldPatternPixel = mInputFieldPattern.cpixel(0, 0);

                for (size_t x = patternPos.x + 1; x > 1; --x)
                    if (screen.cpixel(x - 1, patternPos.y) != inputFieldPatternPixel)
                        return Offset{ x - 1, patternPos.y };

                return{};
            }

            boost::optional<Rect> LootTabFinder::findInputFieldRect(const graphics::Image& screen) const
            {
                const auto patternPos = screen.find(mInputFieldPattern);

                if (!patternPos)
                    return{};

                const auto begin = findBeginOfInputField(screen, Offset::from(*patternPos));

                if (!begin)
                    return{};

                const auto end = findEndOfInputField(screen, Offset::from(*patternPos));

                if (!end)
                    return{};

                return Rect{ static_cast<int>((*begin).x),
                             static_cast<int>((*begin).y),
                             (*end).x - (*begin).x,
                             mInputFieldPattern.h }; 
            }

            boost::optional<Offset> LootTabFinder::findUpArrowPos(const graphics::Image& screen, const Rect& inputFieldRect) const
            {
                const auto kMinY{ 100 };
                const auto kOffsetFromEndOfInputFieldX{ 53 };

                auto pos = Pos{ inputFieldRect.x + kOffsetFromEndOfInputFieldX, 
                                inputFieldRect.y - static_cast<int>(mUparrowPattern.h) };

                for (; pos.y > kMinY; --pos.y)
                    if (screen.isImageThere(pos, mUparrowPattern))
                        return Offset::from(pos);

                return{};
            }

            Rect LootTabFinder::findAreaRect(const Rect& inputFieldRect, const Offset& upArrowPos) const
            {
                const auto kOffsetFromBeginOfInputFieldX{ -17 };
                const auto kOffsetFromEndOfInputFieldY{ static_cast<size_t>(8) };

                const auto x{ inputFieldRect.x + kOffsetFromBeginOfInputFieldX };

                return Rect{ x,
                             static_cast<int>(upArrowPos.y),
                             upArrowPos.x - static_cast<size_t>(x),
                             inputFieldRect.y - kOffsetFromEndOfInputFieldY };
            }
        }
    }
}
