import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import Qt.labs.settings 1.0

import QQuickMaterialHelper.Components 1.12
import QQuickMaterialHelper.Style 1.12
import QQuickMaterialHelper.Fonts 1.12

import FOYLIGHT.Icons 1.0 as Icons
import FOYLIGHT.Utils 1.0 as Utils

ApplicationWindow
{
    id: window
    width: 1080
    height: 720
    visible: true
	   title: "Foy & Light"
     property int availablePadSize : Math.floor(window.width/18) > 60 ? Math.floor(window.width/18) : 70


  Item {
    Timer {
        interval: 10; running: true; repeat: true
        onTriggered: client.SendSacn(all)

    }
  }


Loader{
  id :_loader
  source : "WindowsPage.qml"
  anchors.fill: parent
  anchors.centerIn :parent
}





}

