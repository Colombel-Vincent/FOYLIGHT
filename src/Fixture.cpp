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

#include <stdint.h>



// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

FOYLIGHT_USING_NAMESPACE;

// ─────────────────────────────────────────────────────────────
//					FUNCTIONS
// ─────────────────────────────────────────────────────────────
Fixture::Fixture(){

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
		if (it->fid() == id)
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
		if (it->fid() == id) {
			delete it;
			return true;
		}
	}
	return false;
}

void FixtureList::slideDimmer(int value)
{
	for (auto it : *this) {
		it->setDimmer(value*10);

	}


}

Q_INVOKABLE void FixtureList::slideSpeed(int value)
{
		setSpeed(value*2.5);
}


Q_INVOKABLE void FixtureList::setRGB(qint16 red, qint16 green, qint16 blue)
{
	for (auto it : *this) {
		it->setRGB(red, green, blue);

	}
}


void FixtureList::SinusDim(FixtureList &fe) {
	int i = 0;
	for (auto it : *this) {
		it->setDimmer(abs(sin(it->time())+(i*count()+1)*M_PI/(count()*2)) * 255);
		it->setTime(it->time() + 0.05);
	}
}
void FixtureList::SinusSmoothDim(FixtureList &fe)
{
	int i = 0;
	for (auto it : *this) {
		it->setDimmer(abs(sin(it->time()) + (i*count() + 1)*M_PI / (count() * 2)) * 255);
		it->setTime(it->time() + 0.05);
	}
}
void FixtureList::ChaseSmoothDim(FixtureList & fe, FixtureList & f2)
{
	for (auto it : fe)
		it->setDimmer(255);

	for (auto it : f2)
		it->setDimmer(85);
}
void FixtureList::ChaseDim(FixtureList & fe, FixtureList & f2)
{
	for (auto it : fe)
		it->setDimmer(255);

		for (auto it : f2)
		it->setDimmer(0);
}
void FixtureList::sinusColor(int Speed)
{
	for (auto it : *this) 
	{
		qint16 red = sin(it->time() + M_PI / 2) * 255 < 0 ? 0 : sin(it->time() + M_PI / 2) * 255;
		qint16 blue = sin(it->time() + 7 * M_PI / 6) * 255 < 0 ? 0 : sin(it->time() + 7 * M_PI / 6) * 255;
		qint16 green = sin(it->time() + 11 * M_PI / 6) * 255 < 0 ? 0 : sin(it->time() + 11 * M_PI / 6) * 255;
		it->setRGB(red, green, blue);
		it->setTime(it->time() + 0.05 * speed()*0.05);
	}
}

void FixtureList::SinusColorDegrade( int Speed, colorD color)
{
	static double t = 0;
	for (auto it : *this) {
		qint16 color1 = abs(sin(it->time()) * 255);
		qint16 color2 = abs(sin(it->time() + M_PI / 2) * 255);
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
		it->setTime(it->time() + 0.01 * speed()*0.05);
	}
}


/*list of all effect possible*/
void FixtureList :: ListEffects(int a, int b, int c, int d, int g, int effects, int speed)
{
	static Fixture * itp1 = new Fixture;
	static Fixture * itp2= new Fixture;
	Fixture * itp3 = new Fixture;
	FixtureList   f;
	FixtureList   f2;
	for (auto it : *this) {
		if (g)
			a = it->fid();    // g is for all do the effects
		if (it->fid() == a || it->fid() == b || it->fid() == c || it->fid() == d)
			f.append(it);
		else
			f2.append(it);
	}
		switch (effects) {
		case 0:
			ChaseDim(f, f2);
				break;
		case 1:
			ChaseSmoothDim(f, f2);
			break;
		case 2:
			SinusDim(f);
			break;
		case 3:
			SinusSmoothDim(f);
			break;
		case 4:
			SinusColorDegrade( speed, Magenta);
			break;
		case 5:
			SinusColorDegrade( speed, Cyan);
			break;
		case 6:
			SinusColorDegrade( speed, Magenta);
			break;
		case 7:
			sinusColor( speed);
			break;
		default:
			break;
		}
		/*for (auto it : f) {
			it->setRGB(0, 255, 255);
		}*/
	}



void FixtureList::GroupeEffects( int effects, int Speed, int Gr, int EM)
{

	static int a = 1;
	static int b = 1;
	static double t = 0;
	qDebug() << speed();
	if (effectsChanged()) {
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
		ListEffects( a, a, a, a, 0, effects, Speed);
		a = a < count() ? t>1? a + 1 : a: 1;
		t = t >= 1 ? 0 : t + 0.01*(speed()*0.2);
		break;
	case  1:

		if (EM == lineaire || EM==0)
		{
			ListEffects( a, a + 1, a, a, 0, effects, Speed);
			a = a < count() ? t>1 ? a+2 :a  : 1;
			t = t >= 1 ? 0 : t + 0.01*(speed()*0.2);
		}
		else if (EM == saute || EM == 2)
		{
			a = b == count() ?  1 : t>1 ? a + 1:a  ;
			b = b == count() ? count() / 2 +1 : t>1 ? b + 1:b;
			ListEffects( a, b, a, a, 0, effects, Speed);
			t = t >= 1 ? 0 : t + 0.01*(speed()*0.2);
		}
		else if (EM == embrasse || EM == 1)
		{
			a = a == b+1 ? 1 : t > 1 ? a + 1 :a;
			b = a == 1 ? count() : t > 1 ? b - 1 : b;
			ListEffects( a, b, a, a, 0, effects, Speed);
			t = t >= 1 ? 0 : t + 0.01*(speed()*0.2);
			
		}
		break;
	case 2 :
		ListEffects( a, a + 1, a + 2, a, 0, effects, Speed);
		a = a < count() ? a + 3 : 1;
		break;
	case  3:
		ListEffects( a, a + 1, a + 2, a + 3, 0, effects, Speed);
		a = a < count() ? a + 4 : 1;
		break;
	case 5:
		ListEffects( a, a, a, a, 1, effects, Speed);

		break;
	default:
		break;
	}

}
