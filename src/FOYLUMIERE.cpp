// ─────────────────────────────────────────────────────────────
//					INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header

// Qt Header

// Dependancies Header

// Application Header
#include <FOYLUMIERE.hpp>

// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

FOYLUMIERE_USING_NAMESPACE

// ─────────────────────────────────────────────────────────────
//					FUNCTIONS
// ─────────────────────────────────────────────────────────────

uint32_t Version::GetMajor()
{
	return 1;
}

uint32_t Version::GetMinor()
{
	return FOYLUMIERE_VERSION_MINOR;
}

uint32_t Version::GetPatch()
{
	return FOYLUMIERE_VERSION_PATCH;
}

uint32_t Version::GetTag()
{
	return FOYLUMIERE_VERSION_TAG_HEX;
}

QString Version::GetVersion()
{
	return QString::number(GetMajor()) + "." +
		QString::number(GetMinor()) + "." +
		QString::number(GetPatch()) + "." +
		QString::number(GetTag(), 16);
}
