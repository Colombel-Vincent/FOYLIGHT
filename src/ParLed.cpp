#include "ParLed.hpp"
#include <qdebug.h>
#include <qstring.h>
#include <time.h>


FOYLIGHT_USING_NAMESPACE;
void ParLed::setRGB(qint16 red, qint16 green, qint16 blue) {
	 // ne pas mélanger string et int

	setBlue((uint8_t)blue);
	setGreen((uint8_t)green);
	setRed((uint8_t)red);
	//qDebug() <<"red :"<<  red<<" ; blue :" << getBlue()<<"; green :"<< getGreen();

}

 void ParLed::sendData(uint8_t * data) {
	 if (dimmer() < 15) {
	 	srand(time());
	 	int nombre_aleatoire = rand();
		 data[0] = red()+nombre_aleatoire;
		 data[1] = green()+nombre_aleatoire;
		 data[2] = blue()+nombre_aleatoire;
		 data[3] = white()+nombre_aleatoire;
		 data[4] = warmWhite()+nombre_aleatoire;
		 data[5] = uv()+nombre_aleatoire;
		 data[9] = 0x00;
	 }
	 else {
		 data[0] = red();
		 data[1] = green();
		 data[2] = blue();
		 data[3] = white();
		 data[4] = warmWhite();
		 data[5] = uv();
		 data[9] = dimmer();
	 }
	data[6] = 0x00;
	data[7] = shutter();
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