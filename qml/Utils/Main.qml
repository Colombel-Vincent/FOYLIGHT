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
RowLayout{
    id : _generalRow
    anchors.top : _topbanner.bottom

    Pane{
        Layout.topMargin : 30
        Layout.leftMargin : 15
        id : _masterFaderPane
        contentHeight : window.height/5
        contentWidth : window.width/3
        Layout.alignment: Qt.AlignRight
        elevation : 10
        radius : 4

        Label{
            text : "red : "  //+ "blue : " + led.getBlue() //"Général"
            Layout.alignment: Qt.AlignHCenter
            textType: MaterialStyle.TextType.Title

        }

        contentItem : Flickable{
            id: _flickableG
             clip: true
            contentWidth: width
            contentHeight: _generalLayout.implicitHeight + 2 * MaterialStyle.card.verticalPadding
            interactive : contentHeight > height
            ScrollIndicator.vertical: ScrollIndicator {}

            property int availableWidth :  Math.floor((_padButtonGeneral.width + _testSlider3.width + _colorpicker.width +20) /(window.width/3) )

        GridLayout{
            id: _generalLayout
            columns : (3 - _flickableG.availableWidth)
            rows :1+ _flickableG.availableWidth
                   PadButton{
                        Layout.topMargin : 15
                        id : _padButtonGeneral
                        padIcon : Icons.Manager.power

                     } // pad button

                     Rectangle {
                      width : _testSlider3.width +15
                      height : _testSlider3.height +8
                      Layout.leftMargin : 15
                      border.color : "grey"
                      color : "transparent"
                      border.width : 1
                      radius : 6
                  Utils.Fader{
                        Layout.leftMargin : 4
                        id:_testSlider3
                        from : 0
                        to: MaterialStyle.rawButton.minHeight/2
                        value: MaterialStyle.rawButton.cornerRadius
                        stepSize: 1
                        orientation: Qt.Vertical
                        faderWidth : 15

                     } // fader
                   }

                     ColorPage{
                        Layout.leftMargin : 15
                        id : _colorpicker
                        Layout.fillHeight:true
                        Layout.preferredWidth : 450
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                     }




        } // grid layout

}//flickable
    } // pane
    Pane{

        id : _effectPane
        contentHeight : 200
        Layout.leftMargin : 15
        Layout.topMargin : 20
        Layout.alignment: Qt.AlignRight
        contentWidth : window.width - _masterFaderPane.width - 250
        elevation : 10
        radius : 4
        Label{
            text : "Effets"
            Layout.alignment: Qt.AlignHCenter
            textType: MaterialStyle.TextType.Title
        }
        RowLayout{


           PadButton{
                        Layout.topMargin : 30

                        label : "Pinte anniverssaire"
                     } // pad button

           PadButton{
                        Layout.topMargin : 30

                        label : "chill"
                     } // pad button
             PadButton{
                        Layout.topMargin : 30

                        label : "turn up"
                     } // pad button
          PadButton{
                        Layout.topMargin : 30

                        label : "film"
                     } // pad button
        }
        }
    }
         // pane
        RowLayout{

         Pane{


        id : _dunePane
        contentHeight : 550
        Layout.leftMargin : 85

        Layout.topMargin : _masterFaderPane.height +110
        contentWidth : window.width/4
        elevation : 10
        radius : 4
        Label{
            text : "Dune"
            Layout.alignment: Qt.AlignHCenter
            textType: MaterialStyle.TextType.Title
        }
        RowLayout{
            id : _rowDune


           PadButton{
                        Layout.topMargin : 35
                        padIcon : Icons.Manager.power
                     } // pad button

                  Utils.Fader{
                        Layout.topMargin : 15
                        Layout.leftMargin : 15
                        id:_duneSlider
                        from : 0
                        to: MaterialStyle.rawButton.minHeight/2
                        value: MaterialStyle.rawButton.cornerRadius
                        stepSize: 1
                        orientation: Qt.Vertical
                        faderWidth : 14


                     } // fader
                       ColorPage{
                        Layout.leftMargin : 15
                        id : _colorpicker2
                        Layout.fillHeight:true
                        Layout.preferredWidth : 300
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                     }
        }
          GridLayout{

                    PadButton{
                        Layout.topMargin : 250

                        label : "Chase Fort"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Chase Doux"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Sinus"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Symétrie"
                     } // pad button



            }
        } // pane

        Pane{


        id : _parLedPane
        contentHeight : 550
        Layout.leftMargin : 85

        Layout.topMargin : _masterFaderPane.height +110
        contentWidth : window.width/4
        elevation : 10
        radius : 4
        Label{
            text : "Par led"
            Layout.alignment: Qt.AlignHCenter
            textType: MaterialStyle.TextType.Title
        }
        RowLayout{
                id : _rowParled


           PadButton{
                        Layout.topMargin : 35
                        padIcon : Icons.Manager.power
                     } // pad button


                  Utils.Fader{
                        Layout.topMargin : 15
                        Layout.leftMargin : 15
                        id:_parLedSlider
                        from : 0
                        to: MaterialStyle.rawButton.minHeight/2
                        value: MaterialStyle.rawButton.cornerRadius
                        stepSize: 1
                        orientation: Qt.Vertical
                        faderWidth : 14


                     } // fader
                       ColorPage{
                        Layout.leftMargin : 15
                        id : _colorpicker3
                        Layout.fillHeight:true
                        Layout.preferredWidth : 300
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                     }
                 }

            GridLayout{

                    PadButton{
                        Layout.topMargin : 250

                        label : "Chase Fort"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Chase Doux"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Sinus"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Symétrie"
                     } // pad button



            }


        } // pane

        Pane{


        id : _tradPane
        contentHeight : 550
        Layout.leftMargin : 85

        Layout.topMargin : _masterFaderPane.height +110
        contentWidth : window.width/4
        elevation : 10
        radius : 4
        Label{
            text : "Trad"
            Layout.alignment: Qt.AlignHCenter
            textType: MaterialStyle.TextType.Title
        }
        RowLayout{
            id : _rowTrad

           PadButton{
                        Layout.topMargin : 35
                        padIcon : Icons.Manager.power

                     } // pad button

                  Utils.Fader{
                        Layout.topMargin : 15
                        Layout.leftMargin : 15
                        id:_tradSlider
                        from : 0
                        to: MaterialStyle.rawButton.minHeight/2
                        value: MaterialStyle.rawButton.cornerRadius
                        stepSize: 1
                        orientation: Qt.Vertical
                        faderWidth : 14


                     } // fader




        }
        GridLayout{

            columns : 4
            rows : 2
              PadButton{
                        Layout.topMargin : 250

                        label : "Chase Fort"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Chase Doux"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Sinus"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Symétrie"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 15

                        label : "Rectangle"
                     } // pad button
                       PadButton{
                        Layout.topMargin : 15

                        label : "Scène"
                     } // pad button


        }
        } // pane



}


}


