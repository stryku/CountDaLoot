#pragma once

#include "font/db/CharacterDb.hpp"

namespace cdl
{
    namespace font
    {
        class LootFont
        {
        public:
            explicit LootFont(const db::CharactersDb& db);

        private:
            const db::CharactersDb chars;
        };
    }
}
