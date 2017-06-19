#pragma once

#include "font/db/CharacterDb.hpp"

#include <boost/optional.hpp>

namespace cdl
{
    namespace graphics
    {
        struct Image;
    }

    namespace font
    {
        class LootFont;
    }

    namespace text
    {
        class TextReader
        {
        public:
            TextReader(const font::db::CharactersDb& characters);
            boost::optional<std::string> read(const graphics::Image& img) const;

        private:
            boost::optional<font::db::Character> readChar(const graphics::Image& img, size_t xOffset) const;
            std::vector<bool> calculateLayout(const graphics::Image& img) const;

            const font::db::CharactersDb characters;
        };
    }
}
