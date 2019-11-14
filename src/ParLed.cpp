#include "ParLed.hpp"
#include <qdebug.h>
#include <qstring.h>


FOYLIGHT_USING_NAMESPACE;
void ParLed::setRGB(qint16 red, qint16 green, qint16 blue) {
	 // ne pas m�langer string et int

	setBlue((uint8_t)blue);
	setGreen((uint8_t)green);
	setRed((uint8_t)red);
	//qDebug() <<"red :"<<  red<<" ; blue :" << getBlue()<<"; green :"<< getGreen();

}

 void ParLed::sendData(uint8_t * data) {
	 if (getDimmer() < 15) {
		 data[0] = getRed()+70;
		 data[1] = getGreen()+70;
		 data[2] = getBlue()+70;
		 data[3] = getWhite()+70;
		 data[4] = getwarmWhite()+70;
		 data[5] = getUV()+70;
		 data[9] = 0x00;
	 }
	 else {
		 data[0] = getRed();
		 data[1] = getGreen();
		 data[2] = getBlue();
		 data[3] = getWhite();
		 data[4] = getwarmWhite();
		 data[5] = getUV();
		 data[9] = getDimmer();
	 }
	data[6] = 0x00;
	data[7] = getShutter();
	data[8] = 0x00;


}



ParLed::ParLed() : Fixture()
{
	static int id = 1;
	setFid(id);
	id++;

}
/*
ParLed * ParLedList::getParLed(const int id) const
{
	for (auto it : *this) {
		if (it->getId() == id)
			return it;
	}
	return nullptr;
}

ParLed * ParLedList::insert(ParLed * f)
{
	this->append(f);
	return f;
}

bool ParLedList::removeParLed(const int id)
{
	for (auto it : *this) {
		if (it->getId() == id) {
			delete it;
			return true;
		}
	}
	return false;
}
*/