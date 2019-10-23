#ifndef __PARLED_HPP__
#define __PARLED_HPP__

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
class ParLed :  public Fixture {
	Q_OBJECT
	QSM_REGISTER_OBJ_TO_QML_NO_NAME(ParLed);
protected:
	const uint8_t Coarse = 5;
	const uint8_t RedCoarse = 1;
	const uint8_t GreenCoarse = 2;
	const uint8_t BlueCoarse = 3;
	const uint8_t DimmerCoarse = 5;

	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, red, Red , 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, green, Green, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, blue, Blue, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, white, White, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, warmWhite, warmWhite, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, uv, UV, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, shutter, Shutter, 0);

public :
	ParLed()  ;
	~ParLed() {};
	Q_INVOKABLE void setRGB(qint16 red, qint16 green, qint16 blue);
	void sendData(uint8_t * data) override;





};
FOYLIGHT_NAMESPACE_END

#endif