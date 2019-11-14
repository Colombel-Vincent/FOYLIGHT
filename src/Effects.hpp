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


// ─────────────────────────────────────────────────────────────
//					FUNCTION
// ─────────────────────────────────────────────────────────────

/*All function on color*/
void sinusColor(Fixture * it,int speed);
void SinusColorDegrade(Fixture * it, int speed, colorD color );
void SinusDim (Fixture * it, int speed);
void parLedEffects(FixtureList *f, int a, int b,int c,int d, int g, Effects effects,int speed);
void parLedGroupeEffects(FixtureList *f, Effects effects, int speed, GroupEffects Gr, EffectsMode EM);

/*all function on dimmer*/
//void chaseDim(); {}


FOYLIGHT_NAMESPACE_END

#endif