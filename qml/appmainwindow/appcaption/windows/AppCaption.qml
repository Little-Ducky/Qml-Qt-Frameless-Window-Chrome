import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

BaseCaption {
    implicitHeight: window.caption.height()
    width: window.width

    RowLayout {
        anchors.fill: parent
        spacing: 8

        Label {
            text: window.title

            font.pixelSize: 18
            font.bold: true

            color: "#F4E8FF"

            leftPadding: 14
            rightPadding: 14

            Layout.fillHeight: true

            verticalAlignment: Text.AlignVCenter
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        CaptionButton {
            text: window.visibility === Window.Maximized ? "⧉" : "⛶"

            Layout.alignment: Qt.AlignVCenter
            Layout.fillHeight: true

            onClicked: window.controller.toggleMaximized()
        }

        CaptionButton {
            text: "—"
            Layout.alignment: Qt.AlignVCenter
            Layout.fillHeight: true
            onClicked: window.controller.showMinimized()
        }

        CaptionButton {
            text: "✕"
            Layout.alignment: Qt.AlignVCenter
            Layout.fillHeight: true
            onClicked: window.controller.close()
        }
    }
}
