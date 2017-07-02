#include "view/SummaryItemsUpdater.hpp"

namespace cdl
{
    namespace view
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
