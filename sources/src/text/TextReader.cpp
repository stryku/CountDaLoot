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

        boost::optional<std::string> TextReader::read(const graphics::Image& img) const
        {
            std::string ret;
            size_t offset{ 0 };
            auto character = readChar(img, offset);

            while (character )
            {
                ret += character->character;
                offset += character->width;

                if (offset >= img.w)
                    break;

                character = readChar(img, offset);
            }

            return ret.empty() ? boost::optional<std::string>{} : ret;
        }

        boost::optional<font::db::Character> TextReader::readChar(const graphics::Image& img, size_t xOffset) const
        {
            for (const auto& dbChar : characters.chars())
            {
                const auto rect = Rect{ static_cast<int>(xOffset), 
                                        0, 
                                        dbChar.width, 
                                        dbChar.height };

                const auto sprite = img.getSprite(rect);
                sprite.toCb();
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

            for (const auto& pixel : img.pixels)
                layout.push_back(pixel == kColor);

            return layout;
        }
    }
}
