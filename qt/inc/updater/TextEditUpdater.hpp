#pragma once

#include <QObject>

class QTextEdit;
class QString;

namespace cdl
{
    namespace qt
    {
        class TextEditUpdater : public QObject
        {
            Q_OBJECT

        public:
            explicit TextEditUpdater(QTextEdit& textEdit);

        public:
            void append(const QString& line);

        private slots:
            void appendSlot(const QString& line);

        signals:
            void appendSignal(const QString& line);

        private:
            QTextEdit& mTextEdit;
        };
    }
}
