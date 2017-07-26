#include "loot/tab/TabLootReader.hpp"

#include "data/DataProvider.hpp"
#include "graphics/Image.hpp"

namespace cdl
{
    namespace loot
    {
        namespace tab
        {
            TabLootReader::TabLootReader()
                : mTextReader{ data::DataProvider{}.getCharacterDb() }
            {}

            std::vector<std::string> TabLootReader::read(const graphics::Image& tab) const
            {
                const auto kHourWidth{ 42u };
                const auto kFontHeight{ 13u };

                const auto linesCount = tab.h / kFontHeight;

                Offset offset{ kHourWidth, tab.h - kFontHeight };
                std::vector<std::string> lines;

                for (size_t i = 0; i < linesCount; ++i, offset.y -= kFontHeight)
                {
                    const auto line = mTextReader.read(tab, offset);

                    if (!line || *line == " ")
                        break;

                    lines.emplace_back(*line);
                }

                std::reverse(std::begin(lines), std::end(lines));

                return lines;
            }
        }
    }
}
