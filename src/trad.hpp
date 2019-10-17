#ifndef __TRAD_HPP__
#define __TRAD_HPP__

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
class Trad : public QObject {
	Q_OBJECT
	QSM_REGISTER_OBJ_TO_QML_NO_NAME(Trad);
protected:
	QSM_WRITABLE_AUTO_PROPERTY(uint8_t, channel, Channel);
	QSM_WRITABLE_AUTO_PROPERTY(uint8_t, dimmer, Dimmer);
	QSM_WRITABLE_AUTO_PROPERTY(uint8_t, universe, Universe);
	QSM_WRITABLE_AUTO_PROPERTY(QString, name, Name);

public:
	Trad() {};
	~Trad() {};


};
FOYLIGHT_NAMESPACE_END

#endif