#include "Dune.hpp"

FOYLIGHT_USING_NAMESPACE;

Dune::Dune() : Fixture() {
	static int i =1;
	setFid(i);
	i++;

}

void Dune::sendData(uint8_t * data) {
	if (dimmer() < 2) {
		data[1] = 0x00;
		data[2] = 0x00;
		data[3] = 0x00;
	}
	else {
		data[1] = red();
		data[2] = green();
		data[3] = blue();
	}
	data[0] = dimmer() / 2 + 125;
}

void Dune::setRGB(qint16 red, qint16 green, qint16 blue) {
	// ne pas mélanger string et int
	setBlue((uint8_t)blue);
	setGreen((uint8_t)green);
	setRed((uint8_t)red);


}