import QtQuick 2.15

Rectangle {
    height: 30
    width: 100
    color: "black"

    Rectangle {
        id: rec
        height: 3
        width: 15
        color: "grey"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 5
        NumberAnimation on rotation {
            from: 0
            to: 360
            duration: 1000
            loops: Animation.Infinite
        }
    }

    Text {
        anchors.left: rec.right
        anchors.leftMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        id: fpsText
        color: "white"
        font.pixelSize: 20
        text: FPSCaculator && FPSCaculator.fps
    }
}
