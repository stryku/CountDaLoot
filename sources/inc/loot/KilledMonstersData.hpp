#pragma once

#include "loot/ILootObserver.hpp"

#include <unordered_map>

namespace cdl
{
    namespace loot
    {
        class KilledMonsterData : public ILootObserver
        {
        public:
            void notify(const std::vector<std::string>& lines) override;

        private:
            std::unordered_map<std::string, size_t> mMonsterCount;
            std::unordered_map<std::string, std::unordered_map<std::string, size_t>> mMonstersLoot;
        };
    }
}
