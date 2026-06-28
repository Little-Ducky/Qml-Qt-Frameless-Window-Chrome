#ifndef APPMAINWINDOW_H
#define APPMAINWINDOW_H

#include <QtQml>
#include <QQuickWindow>
#include <QQuickItem>
#include <QCursor>

#include "appcaptioncontroller/AppCaptionController.h"
#include "appwindowcontroller/AppWindowController.h"

class AppMainWindow : public QQuickWindow
{
    Q_OBJECT

    Q_PROPERTY(int RESIZE_BORDER MEMBER RESIZE_BORDER CONSTANT FINAL)
    Q_PROPERTY(AppCaptionController* captionController MEMBER m_captionController CONSTANT FINAL)
    Q_PROPERTY(AppWindowController* windowController MEMBER m_windowController CONSTANT FINAL)

public:
    explicit AppMainWindow(QWindow *parent = nullptr) :
        QQuickWindow(parent),
        m_captionController(new AppCaptionController(this)),
        m_windowController(new AppWindowController(this))
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
    AppCaptionController* m_captionController = nullptr;
    AppWindowController* m_windowController = nullptr;
};

#endif // APPMAINWINDOW_H
