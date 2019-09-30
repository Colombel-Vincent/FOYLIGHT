#ifndef __FOYLIGHT_COMMON_HPP__
#define __FOYLIGHT_COMMON_HPP__

// ─────────────────────────────────────────────────────────────
//					INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header
#include <stdint.h>

// C++ Header

// Qt Header
#include <QString>

// Dependancies Header

// Application Header

// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

#ifdef WIN32
	#ifdef FOYLIGHT_SHARED	// Shared build
		#define FOYLIGHT_API_ __declspec(dllexport)
	#elif FOYLIGHT_STATIC 	// No decoration when building staticlly
		#define FOYLIGHT_API_
	#else 				// Link to lib
		#define FOYLIGHT_API_ __declspec(dllimport)
	#endif
#else
	#define FOYLIGHT_API_
#endif

#ifdef FOYLIGHT_USE_NAMESPACE
#ifndef FOYLIGHT_NAMESPACE
#define FOYLIGHT_NAMESPACE Qqhg
#endif
#define FOYLIGHT_NAMESPACE_START namespace FOYLIGHT_NAMESPACE {
#define FOYLIGHT_NAMESPACE_END }
#define FOYLIGHT_USING_NAMESPACE using namespace FOYLIGHT_NAMESPACE;
#else
#undef FOYLIGHT_NAMESPACE
#define FOYLIGHT_NAMESPACE
#define FOYLIGHT_NAMESPACE_START
#define FOYLIGHT_NAMESPACE_END
#define FOYLIGHT_USING_NAMESPACE
#endif

FOYLIGHT_NAMESPACE_START

class FOYLIGHT_API_ Version
{
public:
	/** Library Major Version */
	static uint32_t GetMajor();
	/** Library Minor Version */
	static uint32_t GetMinor();
	/** Library Patch Version */
	static uint32_t GetPatch();
	/** Library Tag Version */
	static uint32_t GetTag();
	/** Library Version as major.minor.patch.tag */
	static QString GetVersion();
};

FOYLIGHT_NAMESPACE_END

#endif
