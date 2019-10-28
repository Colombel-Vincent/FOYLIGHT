#include "Effects.hpp"
FOYLIGHT_USING_NAMESPACE;
void FL::sinusColor(FixtureList * f, int speed)
{
	static double t = 0;
	for (auto it : *f  ) {
			qint16 red = sin(t+ M_PI/2) * 255 < 0 ? 0 : sin(t+M_PI / 2) * 255;
			qint16 blue = sin(t + 7*M_PI/6) * 255 < 0 ? 0 : sin(t + 7*M_PI / 6) * 255;
			qint16 green = sin(t + 11 * M_PI / 6) * 255 < 0 ? 0 : sin(t + 11 * M_PI / 6) * 255;
			it->setRGB(red,green,blue);
	}
	t= t+0.01;
	
}

void FL::SinusColorDegrade(FixtureList * f, int speed, colorD color)
{
static double t = 0;
qint16 color1 = abs(sin(t)*255);
qint16 color2 = abs(sin(t+M_PI/2)*255);
	switch (color) {
	case 0:
		for(auto it : *f)
			it->setRGB(color1, color2, 0);
		break;
	case 1:
		for (auto it : *f)
			it->setRGB(color1, 0, color2);
		qDebug() << color1;
		break;
	case 2: 
		for (auto it : *f)
			it->setRGB(0, color2, color1);
		break;
	default :
		break;
	}
t = t + 0.01;
}
