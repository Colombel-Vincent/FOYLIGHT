#include "ParLed.hpp"


FOYLIGHT_USING_NAMESPACE;
void ParLed::setRGB(uint8_t red, uint8_t green, uint8_t blue) {
	setBlue(blue);
	setGreen(green);
	setRed(red);
}

 void ParLed::sendData(uint8_t * data) {
	data[0] = getRed();	
	data[1] = getGreen();
	data[2] = getBlue();
	data[3] = 0x00;
	data[4] = getDimmer();
	
}
ParLed::ParLed() : Fixture(){}
