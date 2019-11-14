import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import Qt.labs.settings 1.0

import QQuickMaterialHelper.Components 1.12
import QQuickMaterialHelper.Style 1.12
import QQuickMaterialHelper.Fonts 1.12
import QtQml.Models 2.1


Pane
{
	id: page

	property bool pressed: _colorPicker.pressed
	property real red :_colorPicker.red
    property real  blue :_colorPicker.blue
    property real green :_colorPicker.green
    signal pickerColorChanged()




	ColumnLayout
	{
		anchors.fill: parent
		id: root
		Label
		{
			id: textcolor
			text: "color picker"
			Layout.fillWidth: true
		}
		ColorPicker
		{
			id: _colorPicker
			Layout.fillHeight : true
			Layout.fillWidth: true
			onChanged : pressed()

			 function pressed()
			 {
    			pickerColorChanged()
   			 }
		}


}

}