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
	static int i = 0;
	setId(i);
	i++;
}

Fixture::Fixture(QString name, uint8_t universe, uint8_t channel, uint8_t numberChannel) : Fixture()
{
	setName(name);
	setUniverse(universe);
	setChannel(channel);
	setNumberChannel(numberChannel);
}
