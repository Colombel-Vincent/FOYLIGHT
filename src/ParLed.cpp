#include "ParLed.hpp"
#include <qdebug.h>
#include <qstring.h>


FOYLIGHT_USING_NAMESPACE;
void ParLed::setRGB(qint16 red, qint16 green, qint16 blue) {
	 // ne pas mélanger string et int 
	
	setBlue((uint8_t)blue);
	setGreen((uint8_t)green);
	setRed((uint8_t)red);
	qDebug() <<"red :"<<  red<<" ; blue :" << getBlue()<<"; green :"<< getGreen();
}

 void ParLed::sendData(uint8_t * data) {
	data[0] = getRed();	
	data[1] = getGreen();
	data[2] = getBlue();
	data[3] = 0x00;
	data[4] = 0x00;
	data[5] = 0x00;
	data[6] = getDimmer();
	
}
ParLed::ParLed() : Fixture()
{
	static int id = 1;
	setPid(id);
	id++;

}
