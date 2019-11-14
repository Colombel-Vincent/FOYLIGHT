
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
Pane{


  property bool chasetrad : _chasetrad.enable
  property bool chaseDtrad : _chaseDtrad.enable
  property bool chase4trad : _chase4trad.enable
      Item {
        Timer {
        interval: 10; running: true; repeat: true
        onTriggered : {
          _chasetrad.enable ? trad.GroupeEffects(0,0,0,1) : 0
          _chaseDtrad.enable ?trad.GroupeEffects(1,0,0,0) : 0
          _chase4trad.enable ?trad.GroupeEffects(0,0,1,2) : 0


         chasetrad ?_chasetrad.enable = 1 : _chasetrad.enable=0
          chaseDtrad ?_chaseDtrad.enable = 1 : _chaseDtrad.enable =0
          chase4trad ? _chase4trad.enable = 1 :_chase4trad =0
        }
           }
         }

        id : _tradPane
        contentHeight : 550
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
                        faderWidth :  window.width / 128 < 10 ? 10 : 15
                        onMoved :trad.slideDimmer(_tradSlider.value)

                     } // fader




        }
        GridLayout{

            columns : 4
            rows : 2
               PadButton{
                      id: _chasetrad
                        Layout.topMargin : 250
                        label : "Chase"
                        padSize : window.availablePadSize
                     } // pad button
                      PadButton{
                        id: _chaseDtrad
                        Layout.topMargin : 250

                        label : "Chase doux"
                        padSize : window.availablePadSize
                     } // pad button
                      PadButton{
                        id: _chase4trad
                        Layout.topMargin : 250

                        label : "Chase 4"
                        padSize : window.availablePadSize
                     } // pad button


        }
        } // pane
