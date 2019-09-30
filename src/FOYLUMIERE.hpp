#ifndef __FOYLUMIERE_COMMON_HPP__
#define __FOYLUMIERE_COMMON_HPP__

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
	#ifdef FOYLUMIERE_SHARED	// Shared build
		#define FOYLUMIERE_API_ __declspec(dllexport)
	#elif FOYLUMIERE_STATIC 	// No decoration when building staticlly
		#define FOYLUMIERE_API_
	#else 				// Link to lib 
		#define FOYLUMIERE_API_ __declspec(dllimport)
	#endif
#else
	#define FOYLUMIERE_API_
#endif

#ifdef FOYLUMIERE_USE_NAMESPACE
#ifndef FOYLUMIERE_NAMESPACE
#define FOYLUMIERE_NAMESPACE Qqhg
#endif
#define FOYLUMIERE_NAMESPACE_START namespace FOYLUMIERE_NAMESPACE {
#define FOYLUMIERE_NAMESPACE_END }
#define FOYLUMIERE_USING_NAMESPACE using namespace FOYLUMIERE_NAMESPACE;
#else
#undef FOYLUMIERE_NAMESPACE
#define FOYLUMIERE_NAMESPACE
#define FOYLUMIERE_NAMESPACE_START
#define FOYLUMIERE_NAMESPACE_END
#define FOYLUMIERE_USING_NAMESPACE
#endif

FOYLUMIERE_NAMESPACE_START

class FOYLUMIERE_API_ Version
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

FOYLUMIERE_NAMESPACE_END

#endif
