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

// Oliv Qt
#include <QQuickMaterialHelper.hpp>

// QQuickMaterialHelperGallery
#include <FOYLUMIERE.hpp>

// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

#define FOYLUMIERE_URI "Foy & lumiere"

Q_LOGGING_CATEGORY(QQUICKMATERIALHELPERGALLERY_MAIN_LOGGING_CATEGORY, "qquickHelperGallery")

int main(int argc, char *argv[])
{
	QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	// ────────── REGISTER APPLICATION ──────────────────────────────────────

	QGuiApplication::setOrganizationName("Vincent");
	QGuiApplication::setApplicationName("FOY & Lumiere");	
	QGuiApplication::setOrganizationDomain("www.qquickhelpergallery.com");
	QGuiApplication::setApplicationVersion(Qqhg::Version::GetVersion());

	

	// ────────── COMMAND PARSER ──────────────────────────────────────

	QCommandLineParser parser;
	parser.setApplicationDescription("FOYLUMIERE is an application for control light");
	parser.addHelpOption();
	parser.addVersionOption();

	// Process the actual command line arguments given by the user
	parser.process(app);

	// ────────── PROCESS ARGS ──────────────────────────────────────

	const QStringList args = parser.positionalArguments();

	// ────────── SET QML FONT AND RESSOURCES ──────────

	QQuickStyle::setStyle(QStringLiteral("Material"));
	engine.addImportPath("qrc:///FOYLUMIERE/qml");
	engine.addImportPath("qrc:///");

	// ────────── REGISTER QML TYPE ────────────

	// QSM HELPER
	QQuickMaterialHelper::Helper::loadResources();
	QQuickMaterialHelper::Helper::registerTypes();

	// ────────── LOAD QML MAIN ───────────

	
	engine.load(QUrl("qrc:/FOYLUMIERE/qml/Main.qml"));
	if (engine.rootObjects().isEmpty())
		return -1;

	// ────────── START EVENT LOOP ──────────────────────────────────────
	return app.exec();
}
