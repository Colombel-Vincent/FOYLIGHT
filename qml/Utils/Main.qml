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
    width: 1920
    height: 1080
    visible: true
	title: "Foy & Light"
ToolBar{
    id : _topbanner
    width : parent.width
    height : 60
    Label{
    text : "Foy & Light "
    anchors.centerIn: parent


}
}
GridLayout{
    anchors.top : _topbanner.bottom

    Pane{
        Layout.topMargin : 20
        id : _masterFaderPane
        contentHeight : window.height/5
        contentWidth : window.width/3
        Layout.alignment: Qt.AlignRight
        elevation : 10
        radius : 4

        Label{
            text : "Master"
            Layout.alignment: Qt.AlignHCenter
            textType: MaterialStyle.TextType.Body2
        }

        GridLayout{

                  Fader{
                        id:_testSlider3
                        from : 0
                        to: MaterialStyle.rawButton.minHeight/2
                        value: MaterialStyle.rawButton.cornerRadius
                        stepSize: 1
                        orientation: Qt.Vertical


                     } // fader
                     PadButton{
                        id : _padButtonGeneral
                        text : "test"


                     } // pad button



        } // grid layout


    } // pane
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


