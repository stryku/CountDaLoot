#pragma once

#include "font/db/CharacterDb.hpp"
#include "structs/Pos.hpp"

#include <boost/optional.hpp>

#include <string>

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
            boost::optional<std::string> read(const graphics::Image& img, const Offset& startOffset = Offset{ 0,0 }) const;

        private:
            boost::optional<font::db::Character> readChar(const graphics::Image& img, const Offset& offset) const;
            std::vector<bool> calculateLayout(const graphics::Image& img) const;

            const font::db::CharactersDb characters;
        };
    }
}
