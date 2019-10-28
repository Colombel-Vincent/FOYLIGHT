#ifndef __EFFECTS_HPP__
#define __EFFECTS_HPP__

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
#include <math.h>


// Application Header

FOYLIGHT_NAMESPACE_START
// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────
typedef enum colorD { Orange, Magenta, Cyan }colorD;

// ─────────────────────────────────────────────────────────────
//					FUNCTION
// ─────────────────────────────────────────────────────────────

/*All function on color*/
void sinusColor(FixtureList * f,int speed);
void SinusColorDegrade(FixtureList * f, int speed, colorD color );



/*all function on dimmer*/
//void chaseDim(); {}


FOYLIGHT_NAMESPACE_END

#endif