#pragma once

#include "text/TextReader.hpp"

#include <vector>
#include <string>

namespace cdl
{
    namespace graphics
    {
        struct Image;
    }

    namespace loot
    {
        class TabLootReader
        {
        public:
            explicit TabLootReader();

            std::vector<std::string> read(const graphics::Image& tab) const;

        private:
            text::TextReader mTextReader;
        };
    }
}
