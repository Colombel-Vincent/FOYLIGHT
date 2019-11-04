// ─────────────────────────────────────────────────────────────
//					INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header

// Qt Header

// Dependancies Header

// Application Header
#include "Fixture.hpp"
#include <qdebug.h>
#include <Windows.h>
#include <stdint.h>



// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

FOYLIGHT_USING_NAMESPACE;

// ─────────────────────────────────────────────────────────────
//					FUNCTIONS
// ─────────────────────────────────────────────────────────────
Fixture::Fixture(){
	QObject(parent);
}

Fixture::Fixture(QString name, uint8_t universe, uint8_t channel, uint8_t numberChannel) : Fixture()
{
	setName(name);
	setUniverse(universe);
	setChannel(channel);
	setNumberChannel(numberChannel);
}

Fixture * FixtureList::getFixture(const int id) const
{
	for (auto  it : *this ) {
		if (it->getId() == id)
			return it;
	}
	return nullptr;
}

Fixture * FixtureList::insert(Fixture & f)
{
	this->append(&f);
	
	return &f;
}

bool FixtureList::removeFixture(const int id)
{
	for (auto it : *this) {
		if (it->getId() == id) {
			delete it;
			return true;
		}
	}
	return false;
}

void FixtureList::slideDimmer(int value)
{
	for (auto it : *this) {
		it->setDimmer(value*2.5);
		
	}


}

Q_INVOKABLE void FixtureList::setRGB(qint16 red, qint16 green, qint16 blue)
{
	for (auto it : *this) {
		it->setRGB(red, green, blue);
		
	}
}


void FixtureList::SinusDim(Fixture * it, int speed) {
	it->setDimmer(abs(sin(it->getTime()) * 255));
	it->setTime(it->getTime() + 0.05);
}
void FixtureList::SinusSmoothDim(Fixture * it, int speed)
{
	double dim = abs(sin(it->getTime()) * 255) < 30 ? 60 : abs(sin(it->getTime()) * 255);
	if (dim > 200)
		dim = 200;
	it->setDimmer(dim);
	it->setTime(it->getTime() + 0.01);
}
void FixtureList::ChaseSmoothDim(Fixture * it, int speed)
{

}
void FixtureList::ChaseDim(Fixture * itc, Fixture * itp1,Fixture * itp2, int speed,int count)
{
		itc->setDimmer(100);
		itp1->setDimmer(0);
		itp2->setDimmer(0);
	
}
void FixtureList::sinusColor(Fixture * it, int speed)
{
	qint16 red = sin(it->getTime() + M_PI / 2) * 255 < 0 ? 0 : sin(it->getTime() + M_PI / 2) * 255;
	qint16 blue = sin(it->getTime() + 7 * M_PI / 6) * 255 < 0 ? 0 : sin(it->getTime() + 7 * M_PI / 6) * 255;
	qint16 green = sin(it->getTime() + 11 * M_PI / 6) * 255 < 0 ? 0 : sin(it->getTime() + 11 * M_PI / 6) * 255;
	it->setRGB(red, green, blue);
	it->setTime(it->getTime() + 0.05);

}

void FixtureList::SinusColorDegrade(Fixture * it, int speed, colorD color)
{
	static double t = 0;
	qint16 color1 = abs(sin(it->getTime()) * 255);
	qint16 color2 = abs(sin(it->getTime() + M_PI / 2) * 255);
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
	default:
		break;
	}
	it->setTime(it->getTime() + 0.01);
}


/*list of all effect possible*/
void FixtureList :: ListEffects(int a, int b, int c, int d, int g, int effects, int speed)
{
	static Fixture * itp1 = new Fixture;
	static Fixture * itp2= new Fixture;
	Fixture * itp3 = new Fixture;

	for (auto it : *this) {
		if (g)
			a = it->getId();    // g is for all do the effects
		
		switch (effects) {
		case 0:
			if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
				ChaseDim(it, itp1,itp2, speed,count());
			
				break;
		case 1:
			if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
				ChaseSmoothDim(it, speed);
				break;
		case 2:
			if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
				SinusDim(it, speed);
			break;
		case  3:
			if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
				SinusSmoothDim(it, speed);
				break;
		case 4:
			if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
				SinusColorDegrade(it, speed, Orange);
			break;
		case 5:
			if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
				SinusColorDegrade(it, speed, Cyan);
			break;
		case 6:
			if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
				SinusColorDegrade(it, speed, Magenta);
			break;
		case  7:
			if (it->getId() == a || it->getId() == b || it->getId() == c || it->getId() == d)
				sinusColor(it, speed);
			break;
		default:
			break;
		}
		if(it->getId() == b)
		itp2 = it;
		if(it->getId() == a)
		itp1 = it;
		
		
		
	}

}

void FixtureList::GroupeEffects( int effects, int speed, int Gr, int EM)
{
	
	static int a = 1;
	static int b = 1;
	static double t = 0;
	
	if (getEffectsChanged()) {
		a = 1;
		if (EM == saute)
			b = count() / 2 + 1;
		else if (EM == embrasse)
			b = count();
		else
			b = 1;
		setEffectsChanged(0);
	}
	switch (Gr)
	{
	case 0:
		ListEffects( a, a, a, a, 0, effects, speed);
		a = a < count() ? t>1? a + 1 : a: 1;
		t = t >= 1 ? 0 : t + 0.1;
		break;
	case  1:
		if (EM == lineaire || EM==0)
		{
			ListEffects( a, a + 1, a, a, 0, effects, speed);
			a = a < count() ? t>1 ? a+2 :a  : 1;
			t = t >= 1 ? 0 : t + 0.1;
		}
		else if (EM == saute || EM == 1)
		{
			a = b < count() ? t>1 ? a + 1:a : 0;
			b = b < count() ? t>1 ? b + 1:b : count() / 2 + 1;
			ListEffects( a, b, a, a, 0, effects, speed);
			t = t >= 1 ? 0 : t + 0.1;
		}
		else if (EM == embrasse || EM == 2)
		{
			a = a == b - 1 ? 0 : t > 1 ? a + 1 :a;
			b = a == b - 1 ? count() : t > 1 ? b - 1 : b;
			ListEffects( a, b, a, a, 0, effects, speed);
			t = t >= 1 ? 0 : t + 0.1;
		}
		break;
	case 2 :
		ListEffects( a, a + 1, a + 2, a, 0, effects, speed);
		a = a < count() ? a + 3 : 1;
		break;
	case  3:
		ListEffects( a, a + 1, a + 2, a + 3, 0, effects, speed);
		a = a < count() ? a + 4 : 1;
		break;
	case 5:
		ListEffects( a, a, a, a, 1, effects, speed);
		
		break;
	default:
		break;
	}

}
