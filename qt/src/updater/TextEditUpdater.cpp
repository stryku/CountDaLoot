#include "updater/TextEditUpdater.hpp"

#include <QTextEdit>

namespace cdl
{
    namespace qt
    {
        TextEditUpdater::TextEditUpdater(QTextEdit& textEdit)
            : mTextEdit{ textEdit }
        {
            QObject::connect(this,
                             &TextEditUpdater::appendSignal,
                             this,
                             &TextEditUpdater::appendSlot,
                             Qt::ConnectionType::QueuedConnection);

            QObject::connect(this,
                             &TextEditUpdater::clearSignal,
                             this,
                             &TextEditUpdater::clearSlot,
                             Qt::ConnectionType::QueuedConnection);
        }

        void TextEditUpdater::append(const QString& line)
        {
            emit(appendSignal(line));
        }

        void TextEditUpdater::clear()
        {
            emit(clear());
        }

        void TextEditUpdater::appendSlot(const QString& line)
        {
            mTextEdit.append(line);
        }

        void TextEditUpdater::clearSlot()
        {
            clearDirectly();
        }

        void TextEditUpdater::clearDirectly()
        {
            mTextEdit.clear();
        }
    }
}
