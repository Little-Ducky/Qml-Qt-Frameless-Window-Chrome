#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>

#if defined(_WIN32)
#include "windowsplatform/WindowsPlatform.h"
#elif defined(__APPLE__)
#include "macplatform/MacPlatform.h"
#elif defined(__linux__)
#include "linuxplatform/LinuxPlatform.h"
#endif

namespace Application {

// Registers AppMainWindow as a QML type.
void registerUiTypes()
{
#if defined(_WIN32)
    qmlRegisterType<WindowsPlatform>(
        QML_MODULE,
        1, 0,
        "AppMainWindow"
        );
#elif defined(__APPLE__)
    qmlRegisterType<MacPlatform>(
        QML_MODULE,
        1, 0,
        "AppMainWindow"
        );
#elif defined(__linux__)
    qmlRegisterType<LinuxPlatform>(
        QML_MODULE,
        1, 0,
        "AppMainWindow"
        );
#endif

}
}
#endif // APPLICATION_H

