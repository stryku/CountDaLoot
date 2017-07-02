#include "view/summary/SummaryItemsUpdater.hpp"

namespace cdl
{
    namespace view
    {
        namespace summary
        {
            SummaryItemsUpdater::SummaryItemsUpdater(ui::controls::Table<2>& table)
                : mTable{ table }
            {}

            void SummaryItemsUpdater::update(const std::unordered_map<std::string, size_t>& lootStats)
            {
                mTable.clear();

                for (const auto& pair : lootStats)
                {
                    const auto& item = pair.first;
                    const auto& count = pair.second;

                    mTable.add(item, count);
                }
            }
        }
    }
}
