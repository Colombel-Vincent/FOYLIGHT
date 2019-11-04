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
            text : "General"
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

            property int availableWidth :  Math.floor((_padButtonGeneral.width + _generalSlider.width + _colorpicker.width +20) /(window.width/3) )

        GridLayout{
            id: _generalLayout
            columns : (3 - _flickableG.availableWidth)
            rows :1+ _flickableG.availableWidth
                   PadButton{
                        Layout.topMargin : 15
                        id : _padButtonGeneral
                        padIcon : Icons.Manager.power
                        padSize : window.availablePadSize

                     } // pad button


                  Utils.Fader{
                        Layout.leftMargin : 4
                        id:_generalSlider
                        from : 0
                        to: MaterialStyle.rawButton.minHeight/2
                        value: MaterialStyle.rawButton.cornerRadius
                        stepSize: 1
                        orientation: Qt.Vertical
                        faderWidth : 15
                        onMoved : all.slideDimmer(_generalSlider.value)

                     } // fader


                     ColorPage{
                        Layout.leftMargin : 15
                        id : _colorpicker
                        Layout.fillHeight:true
                        Layout.preferredWidth : window.width / 4.5 < 150 ? 150 : window.width / 4.5
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        onPickerColorChanged:all.setRGB(_colorpicker.red,_colorpicker.green,_colorpicker.blue)

                     }




        } // grid layout

}//flickable
    } // pane
    Pane{

        id : _effectPane
        contentHeight : window.height/5
        Layout.leftMargin : 15
        Layout.topMargin : 20
        Layout.alignment: Qt.AlignRight
        contentWidth : window.width/2
        elevation : 10
        radius : 4

        Label{
            text : "Effets"
            Layout.alignment: Qt.AlignHCenter
            textType: MaterialStyle.TextType.Title
        }




        contentItem : Flickable{
            id: _flickableE
            clip: true
            contentWidth: width
            contentHeight: _effectLayout.implicitHeight + 2 * MaterialStyle.card.verticalPadding
            interactive : contentHeight > height
            ScrollIndicator.vertical: ScrollIndicator {}

            property int availableWidth :  Math.floor((_anniverssaire.width*10 /(_effectPane.width) ))



        GridLayout{
          id: _effectLayout
            columns : (8 - _flickableE.availableWidth)
            rows :1+ _flickableE.availableWidth

           PadButton{
                        id : _anniverssaire
                        Layout.topMargin : 30
                        padSize : window.availablePadSize
                        label : "Pinte anniverssaire"
                     } // pad button

           PadButton{
                        Layout.topMargin : 30
                        padSize : window.availablePadSize
                        label : "chill"
                     } // pad button
             PadButton{
                        Layout.topMargin : 30
                        padSize : window.availablePadSize
                        label : "turn up"
                     } // pad button
          PadButton{
                        Layout.topMargin : 30
                        padSize : window.availablePadSize
                        label : "film"
                     } // pad button
                      PadButton{
                        Layout.topMargin : 30

                        label : "Chase Fort"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        Layout.topMargin : 30

                        label : "Chase Doux"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        Layout.topMargin : 30

                        label : "Sinus"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        Layout.topMargin : 30

                        label : "Symétrie"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        Layout.topMargin : 30

                        label : "Rectangle"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        Layout.topMargin : 30

                        label : "Scène"
                        padSize : window.availablePadSize
                     } // pad button

        }
        }
    }
      }   // pane

      RowLayout{

         Pane{
              Item {
        Timer {
        interval: 10; running: true; repeat: true
        onTriggered : {
          _raimbowDune.enable ? dune.GroupeEffects(0,0,0,0) :0
          _degradeODune.enable ?dune.GroupeEffects(4,0,0,0) :0
          _degradeCDune.enable ?dune.GroupeEffects(5,0,0,0) :0
          _degradeMDune.enable ?dune.GroupeEffects(6,0,0,0) :0
        }
           }
         }


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
                        padSize : window.availablePadSize
                     } // pad button

                  Utils.Fader{
                        Layout.topMargin : 15
                        Layout.leftMargin : 15
                        id:_duneSlider
                        from : 0
                        to: 100
                        value: 50
                        stepSize: 1
                        orientation: Qt.Vertical
                        faderWidth : 14
                        onMoved : dune.slideDimmer(_duneSlider.value)

                     } // fader
                       ColorPage{
                        Layout.leftMargin : 15
                        id : _colorpicker2
                        Layout.fillHeight:true
                        Layout.preferredWidth : window.width / 6 < 150 ? 150 : window.width / 6
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        onPickerColorChanged:dune.setRGB(_colorpicker2.red,_colorpicker2.green,_colorpicker2.blue)
                     }
        }
          GridLayout{

                   PadButton{
                      id: _raimbowDune
                        Layout.topMargin : 250
                        label : "Raimbow"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        id: _degradeODune
                        Layout.topMargin : 250
                        padSize : window.availablePadSize

                        label : "Degrade Orange"
                     } // pad button
                       PadButton{
                        id: _degradeCDune
                        Layout.topMargin : 250
                        padSize : window.availablePadSize

                        label : "Degrade Cyan"
                     } // pad button
                       PadButton{
                        id: _degradeMDune
                        Layout.topMargin : 250
                        label : "Degrade Magenta"
                        padSize : window.availablePadSize
                     } // pad button



            }
        } // pane

        Pane{
      Item {
        Timer {
        interval: 10; running: true; repeat: true
        onTriggered : {
          _raimbowled.enable ? led.GroupeEffects(7,0,5,0) : 0
          _degradeOled.enable ?led.GroupeEffects(4,0,5,0) :0
          _degradeCled.enable ?led.GroupeEffects(5,0,5,0) :0
          _degradeMled.enable ?led.GroupeEffects(6,0,5,0) :0

        }
           }
         }

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
        GridLayout{
                id : _rowParled
           PadButton{
                        Layout.topMargin : 35
                        padIcon : Icons.Manager.power
                        padSize : window.availablePadSize
                     } // pad button


                  Utils.Fader{
                        Layout.topMargin : 15
                        Layout.leftMargin : 15
                        id:_parLedSlider
                        from : 0
                        to: 100
                        value:50
                        stepSize: 1
                        orientation: Qt.Vertical
                        faderWidth : 14
                        onMoved : led.slideDimmer(_parLedSlider.value)
                     } // fader
                       ColorPage{
                        Layout.leftMargin : 15
                        id : _colorpicker3
                        Layout.fillHeight:true
                        Layout.preferredWidth : window.width / 6 < 150 ? 150 : window.width / 6
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        onPickerColorChanged:led.setRGB(_colorpicker3.red,_colorpicker3.green,_colorpicker3.blue)
                     }
                 }

            GridLayout{


                PadButton{
                      id: _chaseled
                        Layout.topMargin : 250

                        label : "Chase"
                        padSize : window.availablePadSize


                     } // pad button

                    PadButton{
                      id: _raimbowled
                        Layout.topMargin : 250
                        label : "Raimbow"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        id: _degradeOled
                        Layout.topMargin : 250

                        label : "Degrade Orange"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        id: _degradeCled
                        Layout.topMargin : 250

                        label : "Degrade Cyan"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        id: _degradeMled
                        Layout.topMargin : 250
                        label : "Degrade Magenta"
                        padSize : window.availablePadSize
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
                        padSize : window.availablePadSize

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
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Chase Doux"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Sinus"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        Layout.topMargin : 250

                        label : "Symétrie"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        Layout.topMargin : 15

                        label : "Rectangle"
                        padSize : window.availablePadSize
                     } // pad button
                       PadButton{
                        Layout.topMargin : 15

                        label : "Scène"
                        padSize : window.availablePadSize
                     } // pad button


        }
        } // pane



}


}


