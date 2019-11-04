/**
 * \brief PsnViewer Main File that:
 * - Initialiaze Qt
 * - Parse command line input
 * - Initialiaze PsnViewer
 * - Register useful type to QML
 * - Install Log Message Handler
 */

// ─────────────────────────────────────────────────────────────
//					INCLUDE
// ─────────────────────────────────────────────────────────────

// Qt
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QtQml>
#include <QFontDatabase>
#include <QDebug>
#include <qudpsocket.h>
// Oliv Qt
#include <QQuickMaterialHelper.hpp>

// QQuickMaterialHelperGallery
#include "FOYLIGHT.hpp"
#include "Sacn.hpp"
#include "ParLed.hpp"
#include "Dune.hpp"
#include "Trad.hpp"
#include "Fixture.hpp"

// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

#define FOYLIGHT_URI "Foy & lumiere"

Q_LOGGING_CATEGORY(QQUICKMATERIALHELPERGALLERY_MAIN_LOGGING_CATEGORY, "qquickHelperGallery")

int main(int argc, char *argv[])
{
	QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;
	FL::FixtureList   all = new FL::FixtureList;
	FL::FixtureList   allP = new FL::FixtureList;
	FL::FixtureList   allD = new FL::FixtureList;
	FL::Sacn * Client = new FL::Sacn;
	FL::ParLed * led1 = new FL::ParLed;
	FL::ParLed * led2 = new FL::ParLed;
	
	/*declaration opf 2 entity*/
	led1->setChannel (1);
	led1->setUniverse(1);
	led1->setName("test");
	led1->setDimmer(255);
	led1->setRGB(255, 255, 255);
	led1->setNumberChannel(10);
	led2->setChannel(11);
	led2->setUniverse(1);
	led2->setName("test2");
	led2->setDimmer(255);
	led2->setRGB(255, 255, 255);
	led2->setNumberChannel(10);



	
	
	for (int i = 0; i < 14; i++) {
		FL::Dune * Dune1 = new FL::Dune;
		Dune1->setChannel(446+i*4);
		Dune1->setUniverse(1);
		Dune1->setName(QString(i));
		Dune1->setDimmer(255);
		Dune1->setRGB(255, 255, 255);
		Dune1->setNumberChannel(4);
		allD.insert(*Dune1);
	}

	
	allP.insert(*led1);
	allP.insert(*led2);
	
	for (auto  it : allP) {
		all.insert(*it);
	}
	for (auto it : allD) {
		all.insert(*it);
	}
	//Client->SendSacn(all);
	
	//Client.HelloUDP();
	
	// ────────── REGISTER APPLICATION ──────────────────────────────────────

	QGuiApplication::setOrganizationName("Vincent");
	QGuiApplication::setApplicationName("FOY & Lumiere");
	QGuiApplication::setOrganizationDomain("www.qquickhelpergallery.com");
	QGuiApplication::setApplicationVersion("1");
	


	// ────────── COMMAND PARSER ──────────────────────────────────────

	QCommandLineParser parser;
	parser.setApplicationDescription("FOYLIGHT is an application for control light");
	parser.addHelpOption();
	parser.addVersionOption();

	// Process the actual command line arguments given by the user
	parser.process(app);

	// ────────── PROCESS ARGS ──────────────────────────────────────

	const QStringList args = parser.positionalArguments();

	// ────────── SET QML FONT AND RESSOURCES ──────────

	QQuickStyle::setStyle(QStringLiteral("Material"));
	engine.addImportPath("qrc:///FOYLIGHT/qml");
	engine.addImportPath("qrc:///");

	// ────────── REGISTER QML TYPE ────────────

	// QSM HELPER
	QQuickMaterialHelper::Helper::loadResources();
	QQuickMaterialHelper::Helper::registerTypes();

	// ────────── LOAD QML MAIN ───────────
	engine.rootContext()->setContextProperty("client", Client);
	engine.rootContext()->setContextProperty("all", &all);
	engine.rootContext()->setContextProperty("led", &allP);
	engine.rootContext()->setContextProperty("dune", &allD);
	
	engine.load(QUrl("qrc:///FOYLIGHT/Utils/Main.qml"));
	if (engine.rootObjects().isEmpty())
		return -1;
		
	// ────────── START EVENT LOOP ──────────────────────────────────────
	
	return app.exec();
}
