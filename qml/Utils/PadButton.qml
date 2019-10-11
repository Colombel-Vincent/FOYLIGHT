/**
 * Copyright (C) Olivier Le Doeuff 2019
 * Contact: olivier.ldff@gmail.com
 */

 // Qt
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Templates 2.12 as T

// Qt Graphical
import QtGraphicalEffects 1.12

// MaterialHelper
import QQuickMaterialHelper.Style 1.12
import QQuickMaterialHelper.Core 1.12
import QQuickMaterialHelper.Components 1.12

import FOYLIGHT.Pads 1.0 as Pads

T.Button
{
    id: control

    implicitWidth: padWidth + leftPadding + rightPadding
    implicitHeight: padHeight + topPadding + bottomPadding
    baselineOffset: contentItem.y + contentItem.baselineOffset

    property bool empty: false
    property bool recording: false
    property bool pause: false
    property bool playback: false

    padding: 4
    spacing: 4
    property double elevation: (control.down ? 8 : 2)

    property var label: ""

    property int padSize: 96
    property int padWidth: padSize
    property int padHeight: padSize

    property string padIcon

    property color foregroundColor: MaterialStyle.primaryTextColorLight

    property color rippleColor: MaterialStyle.rippleColorDark

    background: Item
    {
        id: background

        x: text ? (control.mirrored ? control.width - width - control.rightPadding : control.leftPadding) : control.leftPadding + (control.availableWidth - width) / 2
        y: control.topPadding + (control.availableHeight - height) / 2

        width: control.padWidth
        height: control.padHeight

        property Item control: control
        property alias handle: handle

        Image
        {
            id: handle
            source: (control.empty || (!control.recording && !control.playback && !control.pause)) ? Pads.Manager.padGrey :
            control.recording ? Pads.Manager.padPink : ( control.pause ? Pads.Manager.padOrange : Pads.Manager.padGreen);

            width: parent.width
            height: parent.height
        }

        Ripple
        {
            x: 2
            y: 2
            clipRadius: 5
            width: parent.width - 4
            height: parent.height - 4
            pressed: control.pressed
            anchor: control
            active: control.down || control.visualFocus || control.hovered
            color: control.rippleColor
        }

        // The layer is disabled when the button color is transparent so you can do
        // Material.background: "transparent" and get a proper flat button without needing
        // to set Material.elevation as well
        layer.enabled: control.enabled
        layer.effect: ElevationEffect
        {
            elevation: control.elevation
        }
    }

    contentItem: Item
    {
        implicitWidth: parent.width + control.spacing
        implicitHeight: parent.height + control.spacing

        Label
        {
            id: _label
            text: control.label
            width : parent.width - 10
            textType: MaterialStyle.TextType.Body2
            color: control.foregroundColor
            anchors.centerIn: parent
            wrapMode: Label.Wrap
            verticalAlignment : Label.AlignVCenter
            horizontalAlignment : Label.AlignHCenter
        }

        Image
        {
            id: _padIcon
            source: control.padIcon
            anchors.centerIn: parent
            width: background.width*0.7
            height: background.height*0.7
        }
    }
}