// ─────────────────────────────────────────────────────────────
//					INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header

// Qt Header

// Dependancies Header

// Application Header
#include "FOYLIGHT.hpp"

// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

FOYLIGHT_USING_NAMESPACE

// ─────────────────────────────────────────────────────────────
//					FUNCTIONS
// ─────────────────────────────────────────────────────────────

uint32_t Version::GetMajor()
{
	return 1;
}

uint32_t Version::GetMinor()
{
	return FOYLIGHT_VERSION_MINOR;
}

uint32_t Version::GetPatch()
{
	return FOYLIGHT_VERSION_PATCH;
}

uint32_t Version::GetTag()
{
	return FOYLIGHT_VERSION_TAG_HEX;
}

QString Version::GetVersion()
{
	return QString::number(GetMajor()) + "." +
		QString::number(GetMinor()) + "." +
		QString::number(GetPatch()) + "." +
		QString::number(GetTag(), 16);
}
