#ifndef __PARLED_HPP__
#define __PARLED_HPP__

// ─────────────────────────────────────────────────────────────
//					INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header
#include <QObject>
#include "FOYLIGHT.hpp"
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
class ParLed : public QObject {
	Q_OBJECT
		QSM_REGISTER_OBJ_TO_QML_NO_NAME(ParLed);
protected:
	QSM_WRITABLE_AUTO_PROPERTY(uint8_t, channel, Channel);
	QSM_WRITABLE_AUTO_PROPERTY(uint8_t, universe, Universe);
	QSM_WRITABLE_AUTO_PROPERTY(QString, name, Name);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, red, Red , 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, green, Green, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, blue, Blue, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, white, White, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, warmWhite, warmWhite, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, uv, UV, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, shutter, Shutter, 0);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, dimmer, Dimmer, 100);
public :
	ParLed() {};
	~ParLed() {};
	void setRGB(uint8_t red, uint8_t green, uint8_t blue) {};





};
FOYLIGHT_NAMESPACE_END

#endif