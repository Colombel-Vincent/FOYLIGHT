#include "trad.hpp"

FOYLIGHT_USING_NAMESPACE;

void Trad::sendData(uint8_t * data) {
	data[0] = getDimmer();
}


Trad::Trad() : Fixture()
{
	static int i =1;
	setFid(i);
	i++;
}
