#ifndef __FIXTURE_HPP__
#define __FIXTURE_HPP__

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
class Fixture : public QObject {
protected:
	Q_OBJECT
	QSM_REGISTER_OBJ_TO_QML_NO_NAME(Fixture);
protected:
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, numberChannel, NumberChannel,1);
	QSM_WRITABLE_AUTO_PROPERTY(uint8_t, channel, Channel);
	QSM_WRITABLE_AUTO_PROPERTY(uint8_t, universe, Universe);
	QSM_WRITABLE_AUTO_PROPERTY(QString, name, Name);
	QSM_WRITABLE_AUTO_PROPERTY(int, id, Id);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, dimmer, Dimmer, 100);
public :
	Fixture();
	~Fixture() {};
	virtual void sendData(uint8_t * data) {};





};
FOYLIGHT_NAMESPACE_END

#endif