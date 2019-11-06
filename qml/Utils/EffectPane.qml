
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
        // pane