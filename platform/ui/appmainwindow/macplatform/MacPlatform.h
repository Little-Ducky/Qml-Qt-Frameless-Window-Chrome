#ifndef MACPLATFORM_H
#define MACPLATFORM_H

#include "../AppMainWindow.h"

#include "utils/MacUtils.h"

class MacPlatform : public AppMainWindow
{
    Q_OBJECT
public:
    explicit MacPlatform(QWindow *parent = nullptr);

    Q_INVOKABLE void setup() override;

protected:
    bool nativeEvent(const QByteArray &eventType,
                     void *message,
                     qintptr *result) override;

private:
    MacUtils macUtils;
};

#endif // MACPLATFORM_H
