#include "updater/LabelUpdater.hpp"

#include <QLabel>

namespace cdl
{
    namespace qt
    {
        LabelUpdater::LabelUpdater(QLabel& label)
            : mLabel{ label }
        {
            QObject::connect(this,
                             &LabelUpdater::setTextSignal,
                             this,
                             &LabelUpdater::setTextSlot,
                             Qt::ConnectionType::QueuedConnection);

            QObject::connect(this,
                             &LabelUpdater::setColorSignal,
                             this,
                             &LabelUpdater::setColorSlot,
                             Qt::ConnectionType::QueuedConnection);
        }

        void LabelUpdater::setText(const QString& text)
        {
            emit(setTextSignal(text));
        }

        void LabelUpdater::setColor(const QString& color)
        {
            emit(setColorSignal(color));
        }

        void LabelUpdater::setTextSlot(const QString& text)
        {
            mLabel.setText(text);
        }

        void LabelUpdater::setColorSlot(const QString& color)
        {
            mLabel.setStyleSheet(QString{ "QLabel { color : %1; }" }.arg(color));
        }

    }
}
