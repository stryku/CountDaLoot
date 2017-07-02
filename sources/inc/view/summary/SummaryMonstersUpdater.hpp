#pragma once

#include "ui/controls/Table.hpp"

#include <mutex>
#include <unordered_map>
#include <string>

namespace cdl
{
    namespace view
    {
        namespace summary
        {
            class SummaryMonstersUpdater
            {
            public:
                explicit SummaryMonstersUpdater(ui::controls::Table<2>& table);

            public:
                void update(const std::unordered_map<std::string, size_t>& mMonsterCount);

            private:
                ui::controls::Table<2>& mTable;
            };
        }
    }
}
