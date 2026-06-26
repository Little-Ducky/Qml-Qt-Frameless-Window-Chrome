#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>

#if defined(_WIN32)
#include "windowsplatform/WindowsPlatform.h"
#elif defined(__APPLE__)
#include "macplatform/MacPlatform.h"
#elif defined(__linux__)
// Linux
#endif

namespace Application {

// Registers AppMainWindow as a QML type.
// This currently overrides and customizes window behavior only on Windows,
// where native window events are intercepted and replaced with custom logic
// (frameless window, custom title bar, resize handling, system menu, etc.).
// On other platforms, default behavior is used.
void registerUiTypes()
{
#if defined(_WIN32)
    qmlRegisterType<WindowsPlatform>(
        QML_MODULE,
        1, 0,
        "AppMainWindow"
        );
}
#elif defined(__APPLE__)
    qmlRegisterType<MacPlatform>(
        QML_MODULE,
        1, 0,
        "AppMainWindow"
        );
}
#elif defined(__linux__)
// Linux
#endif

}

#endif // APPLICATION_H

