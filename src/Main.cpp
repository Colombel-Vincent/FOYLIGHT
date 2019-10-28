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
	FL::FixtureList *  all = new FL::FixtureList;
	FL::Sacn * Client = new FL::Sacn;
	FL::ParLed * led1 = new FL::ParLed;
	led1->setChannel (1);
	led1->setUniverse(1);
	led1->setName("test");
	led1->setDimmer(255);
	led1->setRGB(255, 125, 255);
	led1->setNumberChannel(10);
	all->insert(*led1);
	Client->SendSacn(all);
	
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
	engine.rootContext()->setContextProperty("all", all);
	engine.rootContext()->setContextProperty("led", led1);
	
	engine.load(QUrl("qrc:///FOYLIGHT/Utils/Main.qml"));
	if (engine.rootObjects().isEmpty())
		return -1;
		
	// ────────── START EVENT LOOP ──────────────────────────────────────
	
	return app.exec();
}
