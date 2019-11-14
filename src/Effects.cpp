#include "Effects.hpp"
FOYLIGHT_USING_NAMESPACE;


void FL::SinusDim(Fixture * it, int speed) {
	it->setDimmer(abs(sin(it->getTime())*255));
	it->setTime(it->getTime() + 0.05);
}
void FL::sinusColor(Fixture * it, int speed)
{
			qint16 red = sin(it->getTime()+ M_PI/2) * 255 < 0 ? 0 : sin(it->getTime() +M_PI / 2) * 255;
			qint16 blue = sin(it->getTime() + 7*M_PI/6) * 255 < 0 ? 0 : sin(it->getTime() + 7*M_PI / 6) * 255;
			qint16 green = sin(it->getTime() + 11 * M_PI / 6) * 255 < 0 ? 0 : sin(it->getTime() + 11 * M_PI / 6) * 255;
			it->setRGB(red,green,blue);
			it->setTime(it->getTime() + 0.01);

}

void FL::SinusColorDegrade(Fixture * it, int speed, colorD color)
{
static double t = 0;
qint16 color1 = abs(sin(it->getTime())*255);
qint16 color2 = abs(sin(it->getTime() +M_PI/2)*255);
	switch (color) {
	case 0:
			it->setRGB(color1, color2, 0);
		break;
	case 1:
			it->setRGB(color1, 0, color2);
		//qDebug() << color1;
		break;
	case 2:
			it->setRGB(0, color2, color1);
		break;
	default :
		break;
	}
	it->setTime(it->getTime() + 0.01);
}


/*list of all effect possible*/
void FL::parLedEffects(FixtureList *f, int a, int b, int c, int d, int g, Effects effects, int speed)
{
	
for (auto it : *f) {
	if (g)
		a = it->getId();    // g is for all do the effects
	
	switch (effects) {
	case Chase:
		if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
		break;
	case ChaseDoux:
		if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
		break;
	case Sin:
		if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
			SinusDim(it, speed);
		break;
	case SinDoux:
		if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
		break;
	case DegradeO:
		if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
			SinusColorDegrade(it, speed, Orange);
		break;
	case DegradeC:
		if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
			SinusColorDegrade(it, speed, Cyan);
		break;
	case DegradeM:
		if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
			SinusColorDegrade(it, speed, Magenta);
		break;
	case Raimbow:
		if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
			sinusColor(it, speed);
		break;
	default:
		break;
	}
	}

}

void FL::parLedGroupeEffects(FixtureList *f, Effects effects, int speed,GroupEffects Gr,EffectsMode EM)
{
	static int a = 1;
	static int b = 1;
	if (f->getEffectsChanged()) {
		a = 1;
		if (EM == saute)
			b = f->count() / 2 + 1;
		else if (EM == embrasse)
			b = f->count();
		else
			b = 1;
		f->setEffectsChanged(0);
	}
	switch (Gr) 
	{
	case parUn :
		parLedEffects(f,a,a,a,a,0, effects,speed);
		a = a < f->count() ? a+1 : 1;
		//qDebug() << "a:" << a;
		break;
	case par2 :
		if (EM == lineaire) 
		{
			parLedEffects(f, a, a + 1, a,a, 0, effects, speed);
			a = a < f->count() ? a + 2 : 1;
		}
		else if (EM == saute) 
		{
			a = b < f->count() ? a+1 : 0;
			b = b < f->count() ? b+1 : f->count() / 2 + 1;
			parLedEffects(f, a, b, a,a, 0, effects, speed);
		}
		else if (EM== embrasse)
		{
			a = a == b - 1 ? 0 : a+1;
			b = a == b - 1 ? f->count() : b-1;
			parLedEffects(f, a, b, a,a, 0, effects, speed);
		}
		break;
	case par3 :
		parLedEffects(f, a, a + 1, a + 2,a, 0, effects, speed);
		a = a < f->count() ? a + 3 : 1;
		break;
	case par4 :
		parLedEffects(f, a, a + 1, a + 2, a + 3, 0, effects, speed);
		a = a < f->count() ? a + 4 : 1;
		break;
	case tous:
		parLedEffects(f,a,a,a,a, 1, effects, speed);
		break;
	default:
		break;
	}

}