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

 Flickable{
	property int availablesize : Math.floor((_dunePane.width*3.5) /window.width)
            id: _flickableE
            clip: true
            width: window.width
            height : window.height
            contentHeight:  _layoutPane.implicitHeight
            interactive : contentHeight > height
            ScrollIndicator.vertical: ScrollIndicator {}



RowLayout
{
    id : _generalRow
    Utils.General{
    Layout.alignment: Qt.AlignRight
    id:_generalPane
    Layout.topMargin : 100
    Layout.leftMargin : 15
    }

    Utils.EffectPane{
      Layout.leftMargin : 15
      Layout.topMargin : 100
      Layout.alignment: Qt.AlignRight
      id : _effectPane
    }

}
    GridLayout{
      columns : 3 - availablesize
      rows : availablesize
      id : _layoutPane
        Utils.DunePane{
        Layout.leftMargin : 25
        Layout.topMargin : _generalPane.height+ _topbanner.height*2
        id : _dunePane
        }

        Utils.ParLedPane{
       Layout.leftMargin : 25
        id : _parLedPane
        Layout.topMargin : _generalPane.height+ _topbanner.height*2
}

        Utils.TradPane{
        Layout.leftMargin : 25
        id : _tradPane
        Layout.topMargin : _generalPane.height+ _topbanner.height*2

}


}
}