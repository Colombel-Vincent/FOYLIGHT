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
#include <QQmlObjectListModel>


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
	Fixture(QString name,uint8_t universe, uint8_t channel, uint8_t NumberChannel);
	~Fixture() {};
	virtual void sendData(uint8_t * data) {};





};
/*Fixure list manage a fixture list*/
class  FixtureList : public Qqm::QQmlObjectListModel<Fixture>
{
	Q_OBJECT
	QSM_REGISTER_OBJ_TO_QML_NO_NAME(FixtureList);

private:

	QMap<quint16, Fixture * > _lookupTable;

protected:

	class Fixture * _parentCard = nullptr;
	using Qqm::QQmlObjectListModel<Fixture>::insert;
	using Qqm::QQmlObjectListModel<Fixture>::remove;

public:
	FixtureList(QObject * parent = nullptr) : QQmlObjectListModel<Fixture>(parent) {}
	Fixture * getFixture(const int id) const;
	Fixture* insert(Fixture &f);
	bool removeFixture(const int id);


};
FOYLIGHT_NAMESPACE_END








#endif