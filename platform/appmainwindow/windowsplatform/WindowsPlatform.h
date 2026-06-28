#ifndef WINDOWSPLATFORM_H
#define WINDOWSPLATFORM_H

#include "AppMainWindow/AppMainWindow.h"

#include <QObject>
#include <QQuickWindow>

class WindowsPlatform : public AppMainWindow
{
    Q_OBJECT
public:
    explicit WindowsPlatform(QWindow *parent = nullptr);

    Q_INVOKABLE void setup() override;

protected:
    bool nativeEvent(const QByteArray &eventType,
                     void *message,
                     qintptr *result) override;
};

#endif // WINDOWSPLATFORM_H
