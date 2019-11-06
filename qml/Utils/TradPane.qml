
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
