
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

        contentWidth : 200
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
                        faderWidth :  window.width / 128 < 10 ? 10 : 15
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