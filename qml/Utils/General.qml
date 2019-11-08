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


        id : _masterFaderPane
        contentHeight : 200
        contentWidth : 200

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
            columns : (4 - _flickableG.availableWidth)
            rows :1+ _flickableG.availableWidth
                   PadButton{
                        Layout.topMargin : 15
                        id : _padButtonGeneral
                        padIcon : Icons.Manager.power
                        padSize : window.availablePadSize

                     } // pad button


                  Utils.Fader{
                        Layout.leftMargin : 15
                        id:_generalSlider
                        from : 0
                        to: MaterialStyle.rawButton.minHeight/2
                        value: MaterialStyle.rawButton.cornerRadius
                        stepSize: 1
                        orientation: Qt.Vertical
                        faderWidth :  window.width / 128 < 10 ? 10 : 15
                        onMoved :{ all.slideDimmer(_generalSlider.value)
                        }

                     } // fader

                     Utils.Fader{
                        Layout.leftMargin : 30
                        id:_generalEffectSlider
                        from : 0
                        to: MaterialStyle.rawButton.minHeight/2
                        value: MaterialStyle.rawButton.cornerRadius
                        stepSize: 1
                        orientation: Qt.Vertical
                        faderWidth : window.width / 128 < 10 ? 10 : 15
                        onMoved : {
                        	dune.slideSpeed(_generalEffectSlider.value)
                        	led.slideSpeed(_generalEffectSlider.value)
                        }

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
