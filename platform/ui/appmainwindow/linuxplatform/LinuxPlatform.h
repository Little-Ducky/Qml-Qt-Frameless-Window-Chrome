#ifndef LINUXPLATFORM_H
#define LINUXPLATFORM_H

#include "../AppMainWindow.h"

class LinuxPlatform : public AppMainWindow
{
    Q_OBJECT

public:
    explicit LinuxPlatform(QWindow *parent = nullptr);

    Q_INVOKABLE void setup() override;

protected:
    bool nativeEvent(const QByteArray &eventType,
                     void *message,
                     qintptr *result) override;

    bool event(QEvent *e);

private:
    Qt::Edges resizeEdges(const QPointF &pos) const;
};


#endif // LINUXPLATFORM_H