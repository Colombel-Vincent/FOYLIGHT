import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import Qt.labs.settings 1.0

import QQuickMaterialHelper.Components 1.12
import QQuickMaterialHelper.Style 1.12
import QQuickMaterialHelper.Fonts 1.12

ApplicationWindow
{
    id: window
    width: 1080
    height: 720
    visible: true
	title: "Foy & Light"
ToolBar{
    id : _topbanner
    width : parent.width
    height : 50
Label{
    text : "Application pour s'occuper des light comme un pro"
    Layout.fillWidth : true
    Layout.fillHeight : true
    Layout.alignment: Qt.AlignHCenter
    textType: MaterialStyle.TextType.Body2
    wrapMode: Label.Wrap
}
}
GridLayout{
    anchors.top : _topbanner.bottom

    Pane{
        id : _masterFaderPane
        contentHeight : window.height - _topbanner.height - 100
        contentWidth : 150
        Layout.alignment: Qt.AlignRight

        elevation : 10
        radius : 4

        GridLayout{

         Card{
            padding : 5
          width : 100
          height : 200

        Label{
            text : "Master"
            Layout.alignment: Qt.AlignHCenter
            textType: MaterialStyle.TextType.Body2
        }

        }



        }


    }
    Pane{

        id : _buttonFaderPane
        contentHeight : 200
        contentWidth : 200
        elevation : 10
        radius : 4
        ColumnLayout{


            RaisedButton{
                text : "Pinte d'anniverssaire"
                width : 175
                Layout.alignment: Qt.AlignCenter
            }
            RaisedButton{
                text : "Turn up "
                width : 175
                Layout.alignment: Qt.AlignCenter
            }
            RaisedButton{
                text : "Biere PONG "
                width : 175
                Layout.alignment: Qt.AlignCenter
            }
            RaisedButton{
                text : "Film "
                width : 175
                Layout.alignment: Qt.AlignCenter
            }
        }
        }



        }

}


