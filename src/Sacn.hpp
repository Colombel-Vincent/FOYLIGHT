#ifndef __SACN_HPP__
#define __SACN_HPP__

// ─────────────────────────────────────────────────────────────
//					INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header


// Dependancies Header

// Application Header
#include "FOYLIGHT.hpp"
#include <qobject.h>
#include <qudpsocket.h>

// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

FOYLIGHT_NAMESPACE_START

// ─────────────────────────────────────────────────────────────
//					CLASS
// ─────────────────────────────────────────────────────────────

/**
 */
class Sacn : public QObject
{
	Q_OBJECT;
public:
	 Sacn(QObject * parent = 0);
	void HelloUDP();
	public slots : 
	void readyRead();
private : 
	QUdpSocket *socket;
};

FOYLIGHT_NAMESPACE_END

#endif
