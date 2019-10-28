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
#include <QQmlObjectListModel>


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
	const uint8_t Coarse = 9;
	const uint8_t RedCoarse = 1;
	const uint8_t GreenCoarse = 2;
	const uint8_t BlueCoarse = 3;
	const uint8_t WhiteCoarse = 4;
	const uint8_t AmberCoarse = 5;
	const uint8_t UVCoarse = 6;
	const uint8_t Shutter = 7;
	const uint8_t DimmerCoarse = 8;

	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, red, Red , 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, green, Green, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, blue, Blue, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, white, White, 0);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, warmWhite, warmWhite, 0);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, uv, UV, 0);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, shutter, Shutter, 0);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, pid, Pid, 0);

public :
	ParLed()  ;
	~ParLed() {};
	Q_INVOKABLE void setRGB(qint16 red, qint16 green, qint16 blue) override;
	void sendData(uint8_t * data) override;





};

class  ParLedList : public Qqm::QQmlObjectListModel<ParLed>
{
	Q_OBJECT
		QSM_REGISTER_OBJ_TO_QML_NO_NAME(ParLedList);

protected:

	QMap<quint16, ParLed * > _lookupTable;

private:

	class ParLed * _parentCard = nullptr;
	using Qqm::QQmlObjectListModel<ParLed>::insert;
	using Qqm::QQmlObjectListModel<ParLed>::remove;

public:
	ParLedList(QObject * parent = nullptr) : QQmlObjectListModel<ParLed>(parent) {}
	ParLed * getParLed(const int id) const;
	ParLed* insert(ParLed *f);
	bool removeParLed(const int id);

};
FOYLIGHT_NAMESPACE_END

#endif