#include "Dune.hpp"

FOYLIGHT_USING_NAMESPACE;

Dune::Dune() : Fixture() {
	static int i =1;
	setId(i);
	i++;

}

void Dune::sendData(uint8_t * data) {
	data[0] = getRed();
	data[1] = getGreen();
	data[2] = getBlue();
	data[4] = getDimmer();
}