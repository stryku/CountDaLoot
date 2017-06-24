#include "view/LootListUpdater.hpp"

namespace cdl
{
    namespace view
    {
        LootListUpdater::LootListUpdater(QTextEdit& textEdit)
            : mTextEditUpdater{ textEdit }
        {
            
        }

        void LootListUpdater::notify(const std::vector<std::string>& lines)
        {
            for (const auto& line : lines)
                mTextEditUpdater.append(QString::fromStdString(line));
        }
    }
}
