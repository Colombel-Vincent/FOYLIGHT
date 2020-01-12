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


Pane
{

    id : _masterFaderPane
    contentHeight : window.height/2 -75
    contentWidth : window.width -75

    elevation : 10
    radius : 4

    Label
    {
        text : "Général"
        Layout.alignment: Qt.AlignHCenter
        textType: MaterialStyle.TextType.Title
        id :_text
    } // laberl

    contentItem : Flickable
    {
        id: _flickableG
        clip: true
        contentWidth: window.width
        contentHeight: _generalLayout.height + _colorpicker.height +_effectLayout.height +200
        interactive : contentHeight > window.height
        ScrollIndicator.vertical: ScrollIndicator {}
        property int availableWidthFader :  Math.floor (-(_padButtonGeneral.width + _generalSlider.width +20 -window.width ))
        property int availableWidthButton : Math.floor(window.width - _chill.width * _effectLayout.columns  )

        Item
        {
            id : _content
            Row
            {
                spacing: _flickableG.availableWidthFader < 450 ? _flickableG.availableWidthFader /4 : 20
                id: _generalLayout
                PadButton
                {
                    y : 50
                    id : _padButtonGeneral
                    padIcon : Icons.Manager.power
                    padSize : window.availablePadSize +20

                } // pad button

                Utils.Fader
                {
                  	texte : "Dimmer"

                     id:_generalSlider
                    from : 0
                    to: MaterialStyle.rawButton.minHeight/2
                    value: MaterialStyle.rawButton.cornerRadius
                    stepSize: 1
                    orientation: Qt.Vertical
                    faderWidth :  window.width / 128 < 10 ? 15 : 20
                    onMoved :{ all.slideDimmer(_generalSlider.value)}
                } // fader

                Utils.Fader
                {
                    texte : "Vitesse effet"
                    id:_generalEffectSlider
                    from : 0
                    to: MaterialStyle.rawButton.minHeight/2
                    value: MaterialStyle.rawButton.cornerRadius
                    stepSize: 1
                    orientation: Qt.Vertical
                    faderWidth : window.width / 128 < 10 ? 15 : 20
                    onMoved :
                    {
                        dune.slideSpeed(_generalEffectSlider.value)
                        led.slideSpeed(_generalEffectSlider.value)
                    }//moved
                } // fader
            } // row

            ColorPage
            {
                anchors.top  : _flickableG.availableWidthFader < 450 ? _generalLayout.bottom : _generalLayout.top
                anchors.left : _flickableG.availableWidthFader < 450 ?  _generalLayout.left : _generalLayout.right
                anchors.topMargin : _flickableG.availableWidthFader < 450 ? 20 : 0
                id : _colorpicker
                contentHeight :  _generalLayout.height
                contentWidth : _flickableG.availableWidthFader < 450 ?  window.width -100  :  _flickableG.availableWidthFader - 250
                onPickerColorChanged:all.setRGB(_colorpicker.red,_colorpicker.green,_colorpicker.blue)

            }// color page

            GridLayout
            {
                anchors.top : _colorpicker.bottom
                id: _effectLayout
                columns : _flickableG.availableWidthButton < 50 ? columns-1 : _flickableG.availableWidthButton < (_flickableG.availableWidthButton + _chill.width)  ? _flickableG.availableWidthButton > 250 ? 5 : columns :  5
                rows :6

                PadButton
                {
                    id : _anniverssaire
                    Layout.topMargin : 30
                    padSize : window.availablePadSize
                    label : "Pinte anniverssaire"
                    onClicked :
                    {
                        _anniverssaire.enable ? _parLedPane.raimbowled = true : _parLedPane.raimbowled = false
                        _anniverssaire.enable ? _dunePane.raimbowDune = true : _dunePane.raimbowDune = false
                        _anniverssaire.enable ? _tradPane.chasetrad = true : _tradPane.chasetrad = false
                    }// on clicked
                } // pad button

                PadButton
                {
                    id : _chill
                    Layout.topMargin : 30
                    padSize : window.availablePadSize
                    label : "chill"
                    onClicked :
                    {
                        _chill.enable ? _parLedPane.degradeOled = true : _parLedPane.degradeOled = false
                        _chill.enable ? _dunePane.degradeODune = true : _dunePane.degradeODune = false
                        _chill.enable ? _tradPane.chaseDtrad = true : _tradPane.chaseDtrad = false
                    } // on clicked
                } // pad button

                PadButton
                {
                    id : _turn
                    Layout.topMargin : 30
                    padSize : window.availablePadSize
                    label : "turn up"
                    onClicked :
                    {
                        _turn.enable ? _parLedPane.raimbowled = true : _parLedPane.raimbowled = false
                        _turn.enable ? _parLedPane.chase4led = true : _parLedPane.chase4led = false
                        _turn.enable ? _dunePane.raimbowDune = true : _dunePane.raimbowDune = false
                        _turn.enable ? _dunePane.chase4Dune = true : _dunePane.chase4Dune = false
                        _turn.enable ? _tradPane.chasetrad = true : _tradPane.chasetrad = false
                    }// on clicked
                } // pad button

                PadButton
                {
                    Layout.topMargin : 30
                    padSize : window.availablePadSize
                    label : "film"
                } // pad button
                PadButton
                {
                    Layout.topMargin : 30
                } // pad Button
            }//grid layout
        }//item
    }//flickable
} // pane