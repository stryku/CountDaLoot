#include "data/DataProvider.hpp"

#include "consts/consts.hpp"
#include "font/db/CharacterDb.hpp"
#include "graphics/Image.hpp"

namespace cdl
{
    namespace data
    {
        graphics::Image DataProvider::getLootTabActive() const
        {
            return graphics::Image::load(consts::img::kLootActivePath);
        }

        graphics::Image DataProvider::getLootTabInactive() const
        {
            return graphics::Image::load(consts::img::kLootInactivePath);
        }

        graphics::Image DataProvider::getLootTabInactiveRed() const
        {
            return graphics::Image::load(consts::img::kLootInactiveRedPath);
        }
        graphics::Image DataProvider::getInputFieldPattern() const
        {
            return graphics::Image::load(consts::img::kInputFieldPatternPath);
        }

        graphics::Image DataProvider::getUpArrowPattern() const
        {
            return graphics::Image::load(consts::img::kUpArrowPatternPathPath);
        }

        font::db::CharactersDb DataProvider::getCharacterDb() const
        {
            return font::db::CharactersDb::load(consts::kFontDatabasePath);
        }
    }
}
