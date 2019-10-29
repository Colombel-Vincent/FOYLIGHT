#ifndef __TRAD_HPP__
#define __TRAD_HPP__

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
class Trad : public Fixture {
	Q_OBJECT
	QSM_REGISTER_OBJ_TO_QML_NO_NAME(Trad);
protected:


public:
	Trad();
	~Trad() {};
	void sendData(uint8_t * data);



};
FOYLIGHT_NAMESPACE_END

#endif