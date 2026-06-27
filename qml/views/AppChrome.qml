import QtQuick 2.15

AppMainWindow {
    id: window

    property color backgroundColorCaption: Gradient {
                                                   GradientStop {
                                                       position: 0.0
                                                       color: "#26133D"
                                                   }

                                                   GradientStop {
                                                       position: 0.5
                                                       color: "#1D102F"
                                                   }

                                                   GradientStop {
                                                       position: 1.0
                                                       color: "#130A22"
                                                   }
                                               }
    visible: false

    AppCaption {
        color: backgroundColorCaption
    }

    Component.onCompleted: {
        // Performs platform-specific window initialization.
        window.setup()

        window.visible = true
    }
}
