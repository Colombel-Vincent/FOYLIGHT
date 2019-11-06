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
typedef enum colorD { Orange, Magenta, Cyan }colorD;
typedef enum Effects { Chase, ChaseDoux, Sin, SinDoux, DegradeO, DegradeC, DegradeM, Raimbow }Effects;
typedef enum GroupEffects { parUn, par2, par3, par4, par7, tous }GroupEffects;
typedef enum EffectsMode { lineaire, embrasse, saute }EffectsMode;

// ─────────────────────────────────────────────────────────────
//					FUNCTION
// ─────────────────────────────────────────────────────────────
class Fixture : public QObject {
protected:
	Q_OBJECT
	QSM_REGISTER_OBJ_TO_QML_NO_NAME(Fixture);
protected:
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, numberChannel, NumberChannel,1);
	QSM_WRITABLE_AUTO_PROPERTY(qint16, channel, Channel);
	QSM_WRITABLE_AUTO_PROPERTY(uint8_t, universe, Universe);
	QSM_WRITABLE_AUTO_PROPERTY(QString, name, Name);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, dimmer, Dimmer, 100);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, fid, Fid, 0);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(double, time, Time, 0);
public :
	Fixture();
	Fixture(QString name,uint8_t universe, uint8_t channel, uint8_t NumberChannel);
	~Fixture() {};
	virtual void sendData(uint8_t * data) {};
	virtual void setRGB(qint16 red, qint16 green, qint16 blue) {};






};
/*Fixure list manage a fixture list*/
class  FixtureList : public Qqm::QQmlObjectListModel<Fixture>
{
	Q_OBJECT
	QSM_REGISTER_OBJ_TO_QML_NO_NAME(FixtureList);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(int, effectsChanged, EffectsChanged,1);
	QSM_WRITABLE_AUTO_PROPERTY_WDEFAULT(uint8_t, speed, Speed, 30);

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
	Q_INVOKABLE void slideDimmer(int value) ;
	Q_INVOKABLE void slideSpeed(int value);
	Q_INVOKABLE void setRGB(qint16 red, qint16 green, qint16 blue);
	void sinusColor(Fixture * it, int speed);
	void SinusColorDegrade(Fixture * it, int speed, colorD color);
	void SinusDim();
	void SinusSmoothDim(Fixture * it, int speed);
	void ChaseSmoothDim(FixtureList & fe, FixtureList & f2);
	void ChaseDim(FixtureList  &f , FixtureList  &f2);
	Q_INVOKABLE void ListEffects( int a, int b, int c, int d, int g, int effects, int speed);
	Q_INVOKABLE void GroupeEffects(int effects, int speed, int Gr, int EM);


};
FOYLIGHT_NAMESPACE_END








#endif