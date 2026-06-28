#ifndef LINUXPLATFORM_H
#define LINUXPLATFORM_H

#include "../AppMainWindow.h"

#include "utils/LinuxUtils.h"

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

    bool event(QEvent *e) override;
};


#endif // LINUXPLATFORM_H