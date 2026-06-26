#ifndef APPMAINWINDOW_H
#define APPMAINWINDOW_H

#include <QtQml>
#include <QQuickWindow>
#include <QQuickItem>
#include <QCursor>

#include "appcaption/AppCaption.h"
#include "appwindowcontroller/AppWindowController.h"

class AppMainWindow : public QQuickWindow
{
    Q_OBJECT

    Q_PROPERTY(int RESIZE_BORDER MEMBER RESIZE_BORDER CONSTANT FINAL)
    Q_PROPERTY(AppCaption* caption MEMBER m_appCaption CONSTANT FINAL)
    Q_PROPERTY(AppWindowController* controller MEMBER m_appWindowController CONSTANT FINAL)

public:
    explicit AppMainWindow(QWindow *parent = nullptr) :
        QQuickWindow(parent),
        m_appCaption(new AppCaption(this)),
        m_appWindowController(new AppWindowController(this))
    {
    }

    virtual void setup() = 0;

public:
    static inline constexpr int RESIZE_BORDER = 4;

protected:
    bool nativeEvent(const QByteArray &eventType,
                     void *message,
                     qintptr *result) override = 0;
protected:
    AppCaption* m_appCaption = nullptr;
    AppWindowController* m_appWindowController = nullptr;
};

#endif // APPMAINWINDOW_H
