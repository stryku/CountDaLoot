#pragma once

namespace cdl
{
    namespace font
    {
        namespace db
        {
            class CharactersDb;
        }
    }

    namespace graphics
    {
        struct Image;
    }

    namespace data
    {
        class DataProvider
        {
        public:
            graphics::Image getLootTabActive() const;
            graphics::Image getLootTabInactive() const;
            graphics::Image getLootTabInactiveRed() const;
            graphics::Image getInputFieldPattern() const;
            graphics::Image getUpArrowPattern() const;

            font::db::CharactersDb getCharacterDb() const;
        };
    }
}
