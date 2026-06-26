import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    implicitHeight: window.caption.height()
    width: window.width

    gradient: Gradient {
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
}
