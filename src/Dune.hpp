#ifndef __DUNE_HPP__
#define __DUNE_HPP__

// ─────────────────────────────────────────────────────────────
//					INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header
#include <QObject>
#include "FOYLIGHT.hpp"
#include "Fixture.hpp"
// Dependencies Header
#include <QQmlPtrPropertyHelpers.h>
#include <QQmlAutoPropertyHelpers.h>


// Application Header

FOYLIGHT_NAMESPACE_START
// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────


// ─────────────────────────────────────────────────────────────
//					FUNCTION
// ─────────────────────────────────────────────────────────────
class Dune: public Fixture {
	Q_OBJECT
	QSM_REGISTER_OBJ_TO_QML_NO_NAME(Dune);
protected:

	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, red, Red , 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, green, Green, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, blue, Blue, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, shutter, Shutter, 0);

public :
	void setRGB(uint8_t red, uint8_t green, uint8_t blue) {};
	Dune() {};
	~Dune() {};
	virtual void sendData(uint8_t * data) {};





};
FOYLIGHT_NAMESPACE_END

#endif