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
#include <string.h>
#include "Fixture.hpp"


// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

FOYLIGHT_NAMESPACE_START

/* Defaults */
#define E131_DEFAULT_PORT 5568
#define WIFI_CONNECT_TIMEOUT 10000 /* 10 seconds */

/* E1.31 Packet Offsets */
#define E131_ROOT_PREAMBLE_SIZE 0
#define E131_ROOT_POSTAMBLE_SIZE 2
#define E131_ROOT_ID 4
#define E131_ROOT_FLENGTH 16
#define E131_ROOT_VECTOR 18
#define E131_ROOT_CID 22

#define E131_FRAME_FLENGTH 38
#define E131_FRAME_VECTOR 40
#define E131_FRAME_SOURCE 44
#define E131_FRAME_PRIORITY 108
#define E131_FRAME_RESERVED 109
#define E131_FRAME_SEQ 111
#define E131_FRAME_OPT 112
#define E131_FRAME_UNIVERSE 113

#define E131_DMP_FLENGTH 115
#define E131_DMP_VECTOR 117
#define E131_DMP_TYPE 118
#define E131_DMP_ADDR_FIRST 119
#define E131_DMP_ADDR_INC 121
#define E131_DMP_COUNT 123
#define E131_DMP_DATA 125

/* E1.31 Private Constants */
const uint16_t _E131_PREAMBLE_SIZE = 0x0010;
const uint16_t _E131_POSTAMBLE_SIZE = 0x0000;
const uint8_t _E131_ACN_PID[] = { 0x41, 0x53, 0x43, 0x2d, 0x45, 0x31, 0x2e, 0x31, 0x37, 0x00, 0x00, 0x00 };
const uint8_t _E131_ROOT_VECTOR[] = { 0x00,0x00,0x00,0x04 };
const uint8_t _E131_ROOT_CID[] =  { 0xfb, 0x3c, 0x10, 0x65 , 0xa1 , 0x7f, 0x4d , 0xe2 ,0x99, 0x19, 0x31 , 0x7a , 0x07 , 0xc1 , 0x00 ,0x52 };//{ 0xef, 0x0a, 0xc8, 0xdd , 0x00 , 0x64, 0x44 , 0x01 ,0xa3, 0xa2, 0x45 , 0x9e , 0xf8 , 0xe6 , 0x14 ,0x3e };
const uint32_t _E131_FRAME_VECTOR[] = { 0x00, 0x00, 0x00,0x02 };
const uint8_t _E131_FRAME_OPTIONS = 0x40;
const uint8_t _E131_DMP_VECTOR = 0x02;
const uint8_t _E131_DMP_TYPE = 0xa1;
const uint16_t _E131_DMP_FIRST_ADDR = 0x0000;
const uint16_t _E131_DMP_ADDR_INC = 0x0001;

/* E1.31 Public Constants */
const uint16_t E131_DEFAULT_PORT_srv = 5568;
const uint8_t E131_DEFAULT_PRIORITY = 0x64;

// ─────────────────────────────────────────────────────────────
//					CLASS
// ─────────────────────────────────────────────────────────────

/**
 */
class Sacn : public QObject
{
	Q_OBJECT;
	QSM_REGISTER_OBJ_TO_QML_NO_NAME(Sacn);
public:
	Sacn(QObject * parent = 0);
	Q_INVOKABLE void SendSacn(FixtureList *f);

public slots:
	int setPacketHeader(const uint16_t universe, const uint16_t num_channels);

private:
	QUdpSocket *socket;
	QByteArray Data;
	uint8_t raw[638];

	static const uint8_t ACN_ID[];
	static const uint32_t VECTOR_ROOT = 4;
	static const uint32_t VECTOR_FRAME = 2;
	static const uint8_t VECTOR_DMP = 2;


#ifndef NO_DOUBLE_BUFFER

#endif

	uint8_t sequence; /* Sequence tracker */


public:
	uint8_t *data; /* Pointer to DMX channel data */
	uint16_t universe; /* DMX Universe of last valid packet */


};

FOYLIGHT_NAMESPACE_END

#endif
