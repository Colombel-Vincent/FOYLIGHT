
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
  property bool raimbowDune : _raimbowDune.enable
  property bool degradeODune : _degradeODune.enable
  property bool degradeMDune : _degradeMDune.enable
  property bool chaseDune : _chaseDune.enable
  property bool chaseDDune : _chaseDDune.enable
  property bool chase4Dune : _Chase4Dune.enable
        Item {
        Timer {
        interval: 10; running: true; repeat: true
        onTriggered : {
          _raimbowDune.enable ? dune.GroupeEffects(7,0,5,0) :0
          _degradeODune.enable ?dune.GroupeEffects(5,0,5,0) :0
          _degradeCDune.enable ?dune.GroupeEffects(6,0,5,0) :0
          _degradeMDune.enable ?dune.GroupeEffects(4,0,5,0) :0
          _chaseDune.enable ? dune.GroupeEffects(0,0,0,0) : 0
          _chaseDDune.enable ?dune.GroupeEffects(1,0,0,0) :0
          _Chase4Dune.enable ?dune.GroupeEffects(0,0,1,2) :0

          raimbowDune ?_raimbowDune.enable = 1 : _raimbowDune.enable =0
          degradeODune ?_degradeODune.enable = 1 :_degradeODune.enable= 0
          degradeMDune ?_degradeMDune.enable = 1 :_degradeMDune.enable = 0
          chaseDune ?_chaseDune.enable = 1 : _chaseDune.enable = 0
          chase4Dune ?_Chase4Dune.enable = 1 :_Chase4Dune.enable = 0
        }
           }
         }
        id : _dunePane
        contentHeight : 550
        contentWidth : 200
        elevation : 10
        radius : 4
          Label{
          text : "Dune"
          textType: MaterialStyle.TextType.Title
          }

         contentItem : Flickable{

            id: _flickableD
            clip: true
            contentWidth: 200
            contentHeight: _rowLayout.implicitHeight + 2 * MaterialStyle.card.verticalPadding
            interactive : contentHeight > height
            ScrollIndicator.vertical: ScrollIndicator {}

            property int availableWidth :  Math.floor((_genralDune.width + _duneSlider.width + _colorpicker2.width +20) /(_dunePane.width) )
  Column{

      spacing : 10
      topPadding : 30
         GridLayout{
          Layout.alignment : Qt.AlignHCenter | Qt.AlignVCenter

          id: _rowLayout
            columns : ( 3 - _flickableD.availableWidth)
            rows :1+ _flickableD.availableWidth

                PadButton{
                        id : _genralDune
                        Layout.topMargin : 35
                        padIcon : Icons.Manager.power
                        padSize : window.availablePadSize +10
                        Layout.alignment : Qt.AlignHCenter | Qt.AlignVCenter
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
                        faderWidth :  window.width / 128 < 10 ? 10 : 15
                        onMoved : dune.slideDimmer(_duneSlider.value)
                        Layout.alignment : Qt.AlignHCenter | Qt.AlignVCenter

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
                      id: _chaseDune
                        Layout.topMargin : 250

                        label : "Chase"
                        padSize : window.availablePadSize


                     } // pad button
                      PadButton{
                        id: _chaseDDune
                        Layout.topMargin : 250

                        label : "Chase doux"
                        padSize : window.availablePadSize
                     } // pad button
                      PadButton{
                        id: _Chase4Dune
                        Layout.topMargin : 250

                        label : "Chase 4"
                        padSize : window.availablePadSize
                     } // pad button

                   PadButton{
                      id: _raimbowDune

                        label : "Raimbow"
                        padSize : window.availablePadSize

                     } // pad button
                       PadButton{
                        id: _degradeODune

                        padSize : window.availablePadSize

                        label : "Degrade Orange"
                     } // pad button
                       PadButton{
                        id: _degradeCDune

                        padSize : window.availablePadSize

                        label : "Degrade Cyan"
                     } // pad button
                       PadButton{
                        id: _degradeMDune

                        label : "Degrade Magenta"
                        padSize : window.availablePadSize
                     } // pad button



            }
          }
        } // pane
        }