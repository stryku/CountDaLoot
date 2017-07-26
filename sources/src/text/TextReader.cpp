#include "text/TextReader.hpp"

#include "graphics/Image.hpp"
#include "font/db/Character.hpp"
#include "structs/Rect.hpp"

namespace cdl
{
    namespace text
    {
        TextReader::TextReader(const font::db::CharactersDb& characters)
            : characters{ characters }
        {}

        boost::optional<std::string> TextReader::read(const graphics::Image& img, const Offset& startOffset) const
        {
            std::string ret;
            Offset offset = startOffset;
            auto character = readChar(img, offset);
            char lastChar{ '\0' };

            while (character )
            {
                if (character->character == ' ' && lastChar == ' ')
                    break;

                lastChar = character->character;
                ret += character->character;
                offset.x += character->width;

                if (offset.x >= img.w)
                    break;

                character = readChar(img, offset);
            }

            return ret.empty() ? boost::optional<std::string>{} : ret;
        }

        boost::optional<font::db::Character> TextReader::readChar(const graphics::Image& img, const Offset& offset) const
        {
            for (const auto& dbChar : characters.chars())
            {
                const auto rect = Rect{ static_cast<int>(offset.x),
                                        static_cast<int>(offset.y),
                                        dbChar.width, 
                                        dbChar.height };

                const auto sprite = img.getSprite(rect);
                const auto layout = calculateLayout(sprite);
                
                if (layout == dbChar.layout)
                     return dbChar;
            }

            return {};
        }

        std::vector<bool> TextReader::calculateLayout(const graphics::Image& img) const
        {
            constexpr Rgba kColor{ 0, 240, 0, 255 };

            std::vector<bool> layout;

            layout.reserve(img.w * img.h);

            for(size_t y = 0; y < img.h; ++y)
                for(size_t x = 0; x < img.w; ++x)
                    layout.push_back(img.cpixel(x, y) == kColor);

            return layout;
        }
    }
}
