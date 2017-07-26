#pragma once

#include <QObject>

class QLabel;

namespace cdl
{
    namespace qt
    {
        class LabelUpdater : public QObject
        {
            Q_OBJECT

        public:
            explicit LabelUpdater(QLabel& mLabel);

        public:
            void setText(const QString& text);
            void setColor(const QString& color);

        private slots:
            void setTextSlot(const QString& text);
            void setColorSlot(const QString& color);

        signals:
            void setTextSignal(const QString& text);
            void setColorSignal(const QString& color);

        private:
            QLabel& mLabel;
        };
    }
}
