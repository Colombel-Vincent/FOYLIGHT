
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

  property bool raimbowled : _raimbowled.enable
  property bool degradeOled : _degradeOled.enable
  property bool degradeMled : _degradeMled.enable
  property bool chaseled : _chaseled.enable
  property bool chaseDled : _chaseDled.enable
  property bool chase4led : _chase4led.enable

  Item
  {
    Timer
    {
      interval: 10; running: true; repeat: true
      onTriggered :
      {
        _raimbowled.enable ? led.GroupeEffects(7,0,5,0) : 0
        _degradeCled.enable ?led.GroupeEffects(5,0,5,0) :0
        _degradeMled.enable ?led.GroupeEffects(6,0,5,0) :0
        _chaseled.enable ? led.GroupeEffects(0,0,0,0) : 0
        _chaseDled.enable ?led.GroupeEffects(1,0,0,0) :0
        _Chase4led.enable ?led.GroupeEffects(0,0,1,2) :0
        raimbowled ?_raimbowled.enable = 1 :_raimbowled.enable = 0
        degradeOled ? _degradeOled.enable = 1 :_degradeOled.enable =  0
        degradeMled ?_degradeMled.enable = 1 : _degradeMled.enable =0
        chaseled ?_chaseled.enable = 1 :_chaseled.enable =  0
        chase4led ?_chase4led.enable = 1 : _chase4led.enable = 0
      } // onTrigered
    }//timer
  }//item

  id : _parLedPane
  contentHeight : window.height/2 -75
  contentWidth : window.width -75

  Label
  {
    text : "Par led"
    Layout.alignment: Qt.AlignHCenter
    textType: MaterialStyle.TextType.Title
  } //label

  contentItem : Flickable
  {
    id: _flickableL
    clip: true
    contentWidth: window.width
    contentHeight: _rowParled.height + _colorpicker3.height +_grid1.height +200
    interactive : contentHeight > window.height
    ScrollIndicator.vertical: ScrollIndicator {}

    property int availableWidthFader :  Math.floor (-(_generalLed.width + _parLedSlider.width +20 -window.width ))
    property int availableWidthButton : Math.floor(window.width - _chaseled.width * _grid1.columns  )

    Item
    {
      id : _content
      Row
      {
        id : _rowParled
        spacing: _flickableL.availableWidthFader < 450 ? _flickableL.availableWidthFader /4 : 20
        PadButton
        {
          y:50
          id : _generalLed
          padIcon : Icons.Manager.power
          padSize : window.availablePadSize
        } // pad button

        Utils.Fader
        {
          texte : "dimmer"
          id:_parLedSlider
          from : 0
          to: 100
          value:50
          stepSize: 1
          orientation: Qt.Vertical
          faderWidth :  window.width / 128 < 10 ? 10 : 15
          onMoved : led.slideDimmer(_parLedSlider.value)
        } // fader
      }//Row

      ColorPage
      {
        id : _colorpicker3
        anchors.top  : _flickableL.availableWidthFader < 450 ? _rowParled.bottom : _rowParled.top
        anchors.left : _flickableL.availableWidthFader < 450 ?  _rowParled.left : _rowParled.right
        anchors.topMargin : _flickableL.availableWidthFader < 450 ? 20 : 0
        contentHeight :  _rowParled.height
        contentWidth : _flickableL.availableWidthFader < 450 ?  window.width -100  :  _flickableL.availableWidthFader - 250
        onPickerColorChanged:led.setRGB(_colorpicker3.red,_colorpicker3.green,_colorpicker3.blue)
      } // color page

      GridLayout
      {
        anchors.top : _colorpicker3.bottom
        columns : _flickableL.availableWidthButton < 50 ? columns-1 : _flickableL.availableWidthButton < (_flickableL.availableWidthButton + _chaseled.width)  ? _flickableL.availableWidthButton > 250 ? 5 : columns :  5
        rows :6
        id : _grid1
        PadButton
        {
          id: _chaseled
          Layout.topMargin : 30
          label : "Chase"
          padSize : window.availablePadSize
        } // pad button
        PadButton
        {
          id: _chaseDled
          Layout.topMargin : 30
          label : "Chase doux"
          padSize : window.availablePadSize
         } // pad button
        PadButton
        {
          id: _Chase4led
          Layout.topMargin : 30
          label : "Chase 4"
          padSize : window.availablePadSize
         } // pad button

        PadButton
        {
          id: _raimbowled
          Layout.topMargin : 30
          label : "Raimbow"
          padSize : window.availablePadSize
        } // pad button
        PadButton
        {
          id: _degradeOled
          Layout.topMargin : 30
          label : "Degrade Orange"
          padSize : window.availablePadSize
        } // pad button
        PadButton
        {
          id: _degradeCled
          Layout.topMargin : 30
          label : "Degrade Cyan"
          padSize : window.availablePadSize
         } // pad button
        PadButton
        {
            id: _degradeMled
            Layout.topMargin : 30
            label : "Degrade Magenta"
            padSize : window.availablePadSize
        } // pad button
      }//grid layout
    }//Item
  } // flickable
}//pane