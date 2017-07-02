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
            class SummaryItemsUpdater
            {
            public:
                explicit SummaryItemsUpdater(ui::controls::Table<2>& table);

            public:
                void update(const std::unordered_map<std::string, size_t>& lootStats);

            private:
                ui::controls::Table<2>& mTable;
            };
        }
    }
}
