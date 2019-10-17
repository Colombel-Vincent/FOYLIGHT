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


// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

FOYLIGHT_NAMESPACE_START

//#define SACN_MSK_HEADER_E1_31 '41','53',"32D45312E3137000000'
#define SACN_MSK_HEADER_E1_31_NBR 16
#define SACN_MSK_FARMING_LAYER_NBR 37
#define SACN_MSK_SACN_NBR_0 55
#define SACN_MSK_NBR
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
const uint8_t _E131_ROOT_CID[] = { 0xef, 0x0a, 0xc8, 0xdd , 0x00 , 0x64, 0x44 , 0x01 ,0xa3, 0xa2, 0x45 , 0x9e , 0xf8 , 0xe6 , 0x14 ,0x3e };
const uint32_t _E131_FRAME_VECTOR[] = { 0x00, 0x00, 0x00,0x02 };
const uint8_t _E131_FRAME_OPTIONS = 0x40;
const uint8_t _E131_DMP_VECTOR = 0x02;
const uint8_t _E131_DMP_TYPE = 0xa1;
const uint16_t _E131_DMP_FIRST_ADDR = 0x0000;
const uint16_t _E131_DMP_ADDR_INC = 0x0001;

/* E1.31 Public Constants */
const uint16_t E131_DEFAULT_PORT_srv = 5568;
const uint8_t E131_DEFAULT_PRIORITY = 0x64;


/* E1.31 Packet Structure */
typedef union {
	struct {
		/* Root Layer */
		uint16_t preamble_size;
		uint16_t postamble_size;
		uint8_t acn_id[12];
		uint16_t root_flength;
		uint32_t root_vector;
		uint8_t cid[16];

		/* Frame Layer */
		uint16_t frame_flength;
		uint32_t frame_vector;
		uint8_t source_name[64];
		uint8_t priority;
		uint16_t reserved;
		uint8_t sequence_number;
		uint8_t options;
		uint16_t universe;

		/* DMP Layer */
		uint16_t dmp_flength;
		uint8_t dmp_vector;
		uint8_t type;
		uint16_t first_address;
		uint16_t address_increment;
		uint16_t property_value_count;
		uint8_t property_values[513];
	} packed;

	uint8_t raw[638];
} e131_packet_t;

/* E1.31 Packet Type */
/* All packet contents shall be transmitted in network byte order (big endian) */
typedef union {
	struct {
		struct { /* ACN Root Layer: 38 bytes */
			uint16_t preamble_size; /* Preamble Size */
			uint16_t postamble_size; /* Post-amble Size */
			uint8_t acn_pid[12]; /* ACN Packet Identifier */
			uint16_t flength; /* Flags (high 4 bits) &amp;amp; Length (low 12 bits) */
			uint32_t vector; /* Layer Vector */
			uint8_t cid[16]; /* Component Identifier (UUID) */
		}  root;

		struct { /* Framing Layer: 77 bytes */
			uint16_t flength; /* Flags (high 4 bits) &amp;amp; Length (low 12 bits) */
			uint32_t vector; /* Layer Vector */
			uint8_t source_name[64]; /* User Assigned Name of Source (UTF-8) */
			uint8_t priority; /* Packet Priority (0-200, default 100) */
			uint16_t reserved; /* Reserved (should be always 0) */
			uint8_t seq_number; /* Sequence Number (detect duplicates or out of order packets) */
			uint8_t options; /* Options Flags (bit 7: preview data, bit 6: stream terminated) */
			uint16_t universe; /* DMX Universe Number */
		}  frame;

		struct { /* Device Management Protocol (DMP) Layer: 523 bytes */
			uint16_t flength; /* Flags (high 4 bits) / Length (low 12 bits) */
			uint8_t vector; /* Layer Vector */
			uint8_t type; /* Address Type &amp;amp; Data Type */
			uint16_t first_addr; /* First Property Address */
			uint16_t addr_inc; /* Address Increment */
			uint16_t prop_val_cnt; /* Property Value Count (1 + number of slots) */
			uint8_t prop_val[513]; /* Property Values (DMX start code + slots data) */
		}  dmp;
	}packed;

	uint8_t raw[638]; /* raw buffer view: 638 bytes */
} e131_packet_tx_t;




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
	uint8_t raw[638];
public slots:
	void readyRead();
	//void UDP(int g);
	int setPacketHeader(const uint16_t universe, const uint16_t num_channels);
	
private:
	QUdpSocket *socket;
	QByteArray Data;
	

	static const uint8_t ACN_ID[];
	static const uint32_t VECTOR_ROOT = 4;
	static const uint32_t VECTOR_FRAME = 2;
	static const uint8_t VECTOR_DMP = 2;
	e131_packet_t pbuff1; /* Packet buffer */
	e131_packet_tx_t pbuff3; /* Packet buffer */
#ifndef NO_DOUBLE_BUFFER
	e131_packet_t pbuff2; /* Double buffer */
	e131_packet_tx_t pbuff4; /* Double buffer */
#endif
	e131_packet_t *pwbuff; /* Pointer to working packet buffer */
	e131_packet_tx_t *pwbuffTX; /* Pointer to working packet TX buffer */
	uint8_t sequence; /* Sequence tracker */

	uint32_t swapf_uint32(uint32_t x);
	uint16_t swapf_uint16(uint16_t x);

public:
	uint8_t *data; /* Pointer to DMX channel data */
	uint8_t       ddStartCode;          /* DD start code data*/
	uint16_t universe; /* DMX Universe of last valid packet */
	e131_packet_t *packet; /* Pointer to last valid packet */
	e131_packet_tx_t *packetTX; /* Pointer to last valid TX packet */

};

FOYLIGHT_NAMESPACE_END

#endif
