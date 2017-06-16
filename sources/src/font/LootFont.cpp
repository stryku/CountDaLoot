#include "font/LootFont.hpp"

namespace cdl
{
    namespace font
    {
        LootFont::LootFont(const db::CharactersDb& db)
            : chars{ db }
        {}
    }
}
