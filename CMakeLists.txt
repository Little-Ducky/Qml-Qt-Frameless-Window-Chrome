cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME AppChrome)
set(QML_MODULE AppChromeModule)

project(${PROJECT_NAME} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(PLATFORM_SOURCES)
set(PLATFORM_QML_FILES)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)

qt_add_executable(${PROJECT_NAME}
    main.cpp
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    QML_MODULE="${QML_MODULE}"
)

if(WIN32)
    list(APPEND PLATFORM_SOURCES
        platform/appmainwindow/windowsplatform/WindowsPlatform.h
        platform/appmainwindow/windowsplatform/WindowsPlatform.cpp
        platform/appmainwindow/windowsplatform/utils/WindowsUtils.h
        platform/appmainwindow/windowsplatform/utils/WindowsUtils.cpp
    )

    list(APPEND PLATFORM_QML_FILES
        qml/appmainwindow/appcaption/windows/DefaultAppCaption.qml
    )

elseif(APPLE)
    list(APPEND PLATFORM_SOURCES
        platform/appmainwindow/macplatform/MacPlatform.h
        platform/appmainwindow/macplatform/MacPlatform.mm
        platform/appmainwindow/macplatform/utils/MacUtils.h
        platform/appmainwindow/macplatform/utils/MacUtils.cpp
    )

    list(APPEND PLATFORM_QML_FILES
        qml/appmainwindow/appcaption/mac/DefaultAppCaption.qml
    )

elseif(UNIX)
    list(APPEND PLATFORM_SOURCES
        platform/appmainwindow/linuxplatform/LinuxPlatform.h
        platform/appmainwindow/linuxplatform/LinuxPlatform.cpp
        platform/appmainwindow/linuxplatform/utils/LinuxUtils.h
        platform/appmainwindow/linuxplatform/utils/LinuxUtils.cpp
    )

    list(APPEND PLATFORM_QML_FILES
        qml/appmainwindow/appcaption/linux/DefaultAppCaption.qml
    )
endif()

qt_add_qml_module(${PROJECT_NAME}
    URI ${QML_MODULE}

    QML_FILES
        Main.qml

        qml/appmainwindow/appcaption/BaseCaption.qml

        qml/views/AppChrome.qml

        qml/appmainwindow/controls/buttons/DefaultCaptionButton.qml

        ${PLATFORM_QML_FILES}

        qml/tests/CustomCaption.qml

        qml/tests/controls/CustomCaptionButton.qml

    SOURCES
        application/Application.h

        platform/appmainwindow/AppMainWindow.h

        platform/appmainwindow/appcaptioncontroller/AppCaptionController.h
        platform/appmainwindow/appcaptioncontroller/AppCaptionController.cpp

        platform/appmainwindow/appwindowcontroller/AppWindowController.h
        platform/appmainwindow/appwindowcontroller/AppWindowController.cpp

        ${PLATFORM_SOURCES}
        platform/appmainwindow/appcaptioncontroller/AppCaptionController.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/platform
    ${CMAKE_CURRENT_SOURCE_DIR}/platform/appmainwindow
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick
)

install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)