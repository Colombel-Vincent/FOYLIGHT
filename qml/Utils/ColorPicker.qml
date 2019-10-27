import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import Qt.labs.settings 1.0

import QQuickMaterialHelper.Components 1.12
import QQuickMaterialHelper.Style 1.12
import QQuickMaterialHelper.Fonts 1.12
import QtGraphicalEffects 1.0
import FOYLIGHT.Icons 1.0 as Icons
Item
{
    id: control
    property bool pressed: mouseArea.pressed
    property var red
    property var  blue
    property var green

    function setColor(x,y)
    {
        if (x < colorPicker.width/3)
        {
            red = x *-255/(colorPicker.width/3) + 255
            green = x*255/(colorPicker.width/3)
            blue = 0
        }
        else if(x > (2*colorPicker.width/3))
        {
            x = x - (2*colorPicker.width/3)
            red = x*255/(colorPicker.width/3)
            blue = x *-255/(colorPicker.width/3) + 255
            green = 0
        }
        else if(x > (colorPicker.width/3) && x< 2*colorPicker.width/3)
        {
            x = x - colorPicker.width/3
            blue = x*255/(colorPicker.width/3)
            green = x *-255/(colorPicker.width/3) + 255
            red = 0

        }
        red = red + y/colorPicker.height*255
        blue = blue +y/colorPicker.height*255
        green = green + y/colorPicker.height*255
        if (red > 255)
        {
            red =255
        }
        if (red < 0)
        {
            red =0
        }
        if (blue > 255)
        {
            blue = 255
        }
        if (blue < 0)
        {
            blue =0
        }
        if (green >255)
        {
            green = 255
        }
        if (green < 0)
        {
            green = 0
        }

        //console.log(y/colorPicker.height*255)

        led.setRGB(red,green,blue)
    }



    //implicitWidth: colorPicker.width
    implicitHeight: colorPicker.height
    Image
    {
        id: colorPicker
        source: Icons.Manager.colorPicker
        width: parent.width
        height: parent.height
        MouseArea
        {
            id: mouseArea
            anchors.fill: colorPicker
            onPressed:
            {
                cursor.x = mouse.x - 20
                cursor.y = mouse.y - 20
                red  : mouse.x < colorPicker.width/6 ? ((mouse.x+20) *(-255/(colorPicker.width/6) +255) ): (mouse.x+20) < 5*colorPicker.width/6? mouse.x : 0
                setColor(mouse.x,mouse.y)

            }
            onPositionChanged:
            {
                var clampX = (mouse.x > 0 && mouse.x < colorPicker.width) ?  mouse.x : (mouse.x > 0) ? colorPicker.width : 0;
                var clampY = (mouse.y > 0 && mouse.y < colorPicker.height) ? mouse.y : (mouse.y > 0) ? colorPicker.height : 0;
                cursor.x = clampX - 20;
                cursor.y = clampY - 20;

               setColor(mouse.x,mouse.y)

            }
            Image
            {

                id: cursor
                x: width/2
                y: height/2
                source: Icons.Manager.crossCursor
            }
        }
    }

    /*Rectangle
    {
        anchors.fill: parent
        id: rect
        //color: "red"
        /*gradient: Gradient
        {
            GradientStop { position: 0.0; color: Material.color(Material.Red) }
            GradientStop { position: 0.0625; color: Material.color(Material.DeepOrange) }
            GradientStop { position: 0.125; color: Material.color(Material.Orange) }
            GradientStop { position: 0.1875; color: Material.color(Material.Amber) }
            GradientStop { position: 0.25; color: Material.color(Material.Yellow) }
            GradientStop { position: 0.3125; color: Material.color(Material.Lime) }
            GradientStop { position: 0.375; color: Material.color(Material.LightGreen) }
            GradientStop { position: 0.4375; color: Material.color(Material.Green) }
            GradientStop { position: 0.5; color: Material.color(Material.Teal) }
            GradientStop { position: 0.5625; color: Material.color(Material.Cyan) }
            GradientStop { position: 0.625; color: Material.color(Material.LightBlue) }
            GradientStop { position: 0.6875; color: Material.color(Material.Blue) }
            GradientStop { position: 0.75; color: Material.color(Material.Indigo) }
            GradientStop { position: 0.8125; color: Material.color(Material.DeepPurple) }
            GradientStop { position: 0.875; color: Material.color(Material.Purple) }
            GradientStop { position: 0.9375; color: Material.color(Material.Pink) }
            GradientStop { position: 1.0; color: Material.color(Material.Red) }
        }*/
        /*gradient: Gradient
        {
            GradientStop { position: 0.0; color: Qt.rgba(1,0,0,1) }
            GradientStop { position: 0.16; color: Qt.rgba(1,1,0,1) }
            GradientStop { position: 0.33; color: Qt.rgba(0,1,0,1) }
            GradientStop { position: 0.5; color: Qt.rgba(0,1,1,1) }
            GradientStop { position: 0.66; color: Qt.rgba(0,0,1,1)  }
            GradientStop { position: 1.84; color: Qt.rgba(1,0,1,1)  }
            GradientStop { position: 1.0; color: Qt.rgba(1,0, 0,1)  }
        }*/


    //}*/
}