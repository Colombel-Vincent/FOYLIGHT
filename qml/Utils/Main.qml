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
    width: 1920
    height: 1080
    visible: true
	   title: "Foy & Light"
     property int availablePadSize : Math.floor(window.width/18) > 60 ? Math.floor(window.width/18) : 60

  Item {
    Timer {
        interval: 10; running: true; repeat: true
        onTriggered: client.SendSacn(all)
    }
  }
ToolBar{
    id : _topbanner
    width : parent.width
    height : 60
    Label{
    text : "Foy & Light "
    textType: MaterialStyle.TextType.Title
    anchors.centerIn: parent


}
}
RowLayout
{
    id : _generalRow
    anchors.top : _topbanner.bottom

    Utils.General{
    Layout.alignment: Qt.AlignRight
    id:_generalPane
    Layout.topMargin : 30
    Layout.leftMargin : 15
    }

    Utils.EffectPane{
      Layout.leftMargin : 15
      Layout.topMargin : 20
      Layout.alignment: Qt.AlignRight
      id : _effectPane
    }

}

      RowLayout{

        Utils.DunePane{
           Layout.leftMargin : 85
        Layout.topMargin : _generalPane.height +110
        id : _dunePane
        }

        Utils.ParLedPane{
       Layout.leftMargin : 85
        id : _parLedPane
        Layout.topMargin : _generalPane.height +110
}

        Utils.TradPane{
        Layout.leftMargin : 85
        id : _tradPane
        Layout.topMargin : _generalPane.height +110

}


}
}


