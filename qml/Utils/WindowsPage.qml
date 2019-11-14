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

Page{
	header : ToolBar{
    id : _topbanner
    width : parent.width
    height : window.height/18 > 40 ? 60 : 30
    Label{
    text : "FOYLIGHT"
    textType: MaterialStyle.TextType.Title
    anchors.centerIn: parent
}
}
 Flickable{
	property int availablesize : Math.floor((_dunePane.width*3.5) /window.width)
            id: _flickableE
            clip: true
            width: window.width
            height : window.height
            contentHeight:  _view.height
            interactive : contentHeight > height
            ScrollIndicator.vertical: ScrollIndicator {}

SwipeView{

	id : _view
	currentIndex : tabBar.currentIndex
	anchors.fill : parent
	Item{
		id : _general
	ColumnLayout{
	spacing : 10
    Utils.General{

    id:_generalPane

    contentWidth: window.width -75
    contentHeight : window.height/2.5
    }
  	 Utils.EffectPane{

      id : _effectPane
      contentWidth: window.width-75
      contentHeight : window.height/2
    }
}
}

   Item{
 	id : _dune
        Utils.DunePane{


        id : _dunePane
        contentWidth: window.width-75
        contentHeight : window.height
        }
    }

Item{
	id : _parled
        Utils.ParLedPane{

        id : _parLedPane


        contentWidth: window.width-75
        contentHeight : window.height
}
}
Item{
	id : _trad
        Utils.TradPane{

        id : _tradPane
        contentWidth: window.width -75
        contentHeight : window.height
}
}


}
}

footer: FixedTabBar
    {
        id: tabBar
        elevation: 20
        currentIndex:  _view.currentIndex

        model: ListModel
        {
            ListElement{ text: "General" }
            ListElement{ text: "Dune" }
            ListElement{ text: "Par led" }
            ListElement{ text: "Trad" }
        }
    }
}
