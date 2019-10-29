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
