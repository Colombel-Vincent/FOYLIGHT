
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
  property bool raimbowDune : _raimbowDune.enable
  property bool degradeODune : _degradeODune.enable
  property bool degradeMDune : _degradeMDune.enable
  property bool chaseDune : _chaseDune.enable
  property bool chaseDDune : _chaseDDune.enable
  property bool chase4Dune : _Chase4Dune.enable
  Item
  {
    Timer
    {
      interval: 10; running: true; repeat: true
      onTriggered :
      {
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
      } // on trigerred
    }//timer
  }//item

  id : _dunePane
  contentHeight : window.height/2 -75
  contentWidth : window.width -75
  Label
  {
    text : "Dune"
    textType: MaterialStyle.TextType.Title
    Layout.alignment: Qt.AlignHCenter
  }//label

  contentItem : Flickable
  {
    id: _flickableD
    clip: true
    contentWidth: window.width
    contentHeight: _rowDune.height + _colorpicker3.height +_grid2.height +200
    interactive : contentHeight > window.height
    ScrollIndicator.vertical: ScrollIndicator {}

    property int availableWidthFader :  Math.floor (-(_genralDune.width + _duneSlider.width +20 -window.width ))
    property int availableWidthButton : Math.floor(window.width - _chaseDune.width * _grid2.columns  )
    Item
    {
      id : _content
      Row
      {
        spacing: _flickableL.availableWidthFader < 450 ? _flickableL.availableWidthFader /4 : 20
        id : _rowDune

        PadButton
        {
          y: 50
          id : _genralDune
          padIcon : Icons.Manager.power
          padSize : window.availablePadSize +10
        } // pad button

        Utils.Fader
        {
          texte : "dimmer"
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
      } // Row

      ColorPage
      {
        id : _colorpicker2
        anchors.top  : _flickableD.availableWidthFader < 450 ? _rowDune.bottom : _rowDune.top
        anchors.left : _flickableD.availableWidthFader < 450 ?  _rowDune.left : _rowDune.right
        anchors.topMargin : _flickableD.availableWidthFader < 450 ? 20 : 0
        contentHeight :  _rowDune.height
        contentWidth : _flickableD.availableWidthFader < 450 ?  window.width -100  :  _flickableD.availableWidthFader - 250
        onPickerColorChanged:dune.setRGB(_colorpicker2.red,_colorpicker2.green,_colorpicker2.blue)
      } // clor page

      GridLayout
      {
        id : _grid2
        anchors.top : _colorpicker2.bottom
        columns : _flickableD.availableWidthButton < 50 ? columns-1 : _flickableD.availableWidthButton < (_flickableD.availableWidthButton + _chaseDune.width)  ? _flickableD.availableWidthButton > 250 ? 5 : columns :  5
          rows :6
        PadButton
        {
          id: _chaseDune
          Layout.topMargin : 30
          label : "Chase"
          padSize : window.availablePadSize
        } // pad button
        PadButton
        {
          id: _chaseDDune
          Layout.topMargin : 30
          label : "Chase doux"
          padSize : window.availablePadSize
        } // pad button
        PadButton
        {
          id: _Chase4Dune
          Layout.topMargin : 30
          label : "Chase 4"
          padSize : window.availablePadSize
        } // pad button
        PadButton
        {
          id: _raimbowDune
          Layout.topMargin : 30
          label : "Raimbow"
          padSize : window.availablePadSize
        } // pad button
        PadButton
        {
          id: _degradeODune
          Layout.topMargin : 30
          padSize : window.availablePadSize
          label : "Degrade Orange"
        } // pad button
        PadButton
        {
          id: _degradeCDune
          Layout.topMargin : 30
          padSize : window.availablePadSize
          label : "Degrade Cyan"
        } // pad button
        PadButton
        {
          id: _degradeMDune
          Layout.topMargin : 30
          label : "Degrade Magenta"
          padSize : window.availablePadSize
        } // pad button
      }// grid layout
    }//item
  } //glickable
}//pane