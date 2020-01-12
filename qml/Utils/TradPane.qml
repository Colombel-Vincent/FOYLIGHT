
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
  property bool chasetrad : _chasetrad.enable
  property bool chaseDtrad : _chaseDtrad.enable
  property bool chase4trad : _chase4trad.enable
  Item
  {
    Timer
    {
      interval: 10; running: true; repeat: true
      onTriggered :
      {
        _chasetrad.enable ? trad.GroupeEffects(0,0,0,1) : 0
        _chaseDtrad.enable ?trad.GroupeEffects(1,0,0,0) : 0
        _chase4trad.enable ?trad.GroupeEffects(0,0,1,2) : 0
        chasetrad ?_chasetrad.enable = 1 : _chasetrad.enable=0
        chaseDtrad ?_chaseDtrad.enable = 1 : _chaseDtrad.enable =0
        chase4trad ? _chase4trad.enable = 1 :_chase4trad =0
      }//on trigerred
    }//timer
  }//item

id : _tradPane
contentHeight : window.height/2 -75
contentWidth : window.width -75
Label
{
  text : "Trad"
  Layout.alignment: Qt.AlignHCenter
  textType: MaterialStyle.TextType.Title
}
contentItem : Flickable
{
    id: _flickableT
    clip: true
    contentWidth: window.width
    contentHeight: _rowTrad.height +_grid3.height +200
    interactive : contentHeight > window.height
    ScrollIndicator.vertical: ScrollIndicator {}

    property int availableWidthFader :  Math.floor (-(_generalTrad.width + _tradSlider.width +20 -window.width ))
    property int availableWidthButton : Math.floor(window.width - _chasetrad.width * _grid3.columns  )
    Item
    {
      Row
      {
        id : _rowTrad
        spacing: _flickableT.availableWidthFader < 450 ? _flickableT.availableWidthFader /4 : 20
        PadButton
        {
          id: _generalTrad
          padIcon : Icons.Manager.power
          padSize : window.availablePadSize
        } // pad button

        Utils.Fader
        {
          texte : "dimmer"
          id:_tradSlider
          from : 0
          to: MaterialStyle.rawButton.minHeight/2
          value: MaterialStyle.rawButton.cornerRadius
          stepSize: 1
          orientation: Qt.Vertical
          faderWidth :  window.width / 128 < 10 ? 10 : 15
          onMoved :trad.slideDimmer(_tradSlider.value)
        } // fader
      }//Row

      GridLayout
      {
        id : _grid3
        anchors.top : _rowTrad.bottom
        columns : _flickableT.availableWidthButton < 50 ? columns-1 : _flickableT.availableWidthButton < (_flickableT.availableWidthButton + _chasetrad.width)  ? _flickableT.availableWidthButton > 250 ? 5 : columns :  5
        rows :6

        PadButton
        {
          id: _chasetrad
          Layout.topMargin : 30
          label : "Chase"
          padSize : window.availablePadSize
         } // pad button
        PadButton
        {
          id: _chaseDtrad
          Layout.topMargin : 30
          label : "Chase doux"
          padSize : window.availablePadSize
        } // pad button
        PadButton
        {
          id: _chase4trad
          Layout.topMargin : 30
          label : "Chase 4"
          padSize : window.availablePadSize
        } // pad button
      }//grid layotu
    }//item
  } // flickable
}//pane

