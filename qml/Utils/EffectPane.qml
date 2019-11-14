
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

        id : _effectPane
        contentHeight : window.height/5

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
                        onClicked : {
                            _anniverssaire.enable ? _parLedPane.raimbowled = true : _parLedPane.raimbowled = false
                            _anniverssaire.enable ? _dunePane.raimbowDune = true : _dunePane.raimbowDune = false
                            _anniverssaire.enable ? _tradPane.chasetrad = true : _tradPane.chasetrad = false


                        }
                     } // pad button

           PadButton{
                        id : _chill
                        Layout.topMargin : 30
                        padSize : window.availablePadSize
                        label : "chill"
                        onClicked : {
                        _chill.enable ? _parLedPane.degradeOled = true : _parLedPane.degradeOled = false
                        _chill.enable ? _dunePane.degradeODune = true : _dunePane.degradeODune = false
                        _chill.enable ? _tradPane.chaseDtrad = true : _tradPane.chaseDtrad = false
                        }

                    } // pad button
            PadButton{
                        id : _turn
                        Layout.topMargin : 30
                        padSize : window.availablePadSize
                        label : "turn up"
                         onClicked : {
                        _turn.enable ? _parLedPane.raimbowled = true : _parLedPane.raimbowled = false
                        _turn.enable ? _parLedPane.chase4led = true : _parLedPane.chase4led = false
                            _turn.enable ? _dunePane.raimbowDune = true : _dunePane.raimbowDune = false
                            _turn.enable ? _dunePane.chase4Dune = true : _dunePane.chase4Dune = false
                            _turn.enable ? _tradPane.chasetrad = true : _tradPane.chasetrad = false
                            }
                     } // pad button
          PadButton{
                        Layout.topMargin : 30
                        padSize : window.availablePadSize
                        label : "film"
                     } // pad button
                      PadButton{
                        Layout.topMargin : 30

        }
        }
    }
}
        // pane