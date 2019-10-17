// ─────────────────────────────────────────────────────────────
//					INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header

// Qt Header

// Dependancies Header

// Application Header
#include "Sacn.hpp"
#include <qdebug.h>
#include <Windows.h>
#include <stdint.h>
#include <Winsock.h>


// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

FOYLIGHT_USING_NAMESPACE;

int Sacn::setPacketHeader(const uint16_t universe, const uint16_t num_channels) {
	if (pwbuffTX == NULL || universe > 63999 || num_channels < 1 || num_channels > 512) {
		// errno = EINVAL;
		return -1;
	}

	// compute packet layer lengths
	uint16_t prop_val_cnt = num_channels + 1;
	uint16_t dmp_length = prop_val_cnt +
	sizeof pwbuffTX->packed.dmp - sizeof pwbuffTX->packed.dmp.prop_val;
	uint16_t frame_length = sizeof pwbuffTX->packed.frame + dmp_length;
	uint16_t root_length = sizeof pwbuffTX->packed.root.flength +
		sizeof pwbuffTX->packed.root.vector + sizeof pwbuffTX->packed.root.cid + frame_length;

	// clear packet
	memset(packet, 0, sizeof *packet);

	// set Root Layer values
	//preamble_size
	raw[0] = 0x00;
	raw[1] = 0x10;

	//postamble_size
	raw[2] = 0x00;
	raw[3] = 0x00;

	//_E131_ACN_PID
	for (int i = 0 ; i<12 ; i++)
		raw[i+4] = _E131_ACN_PID[i];

	//root.flength

	raw[16] = (0x70 | ((root_length) & 0xFF));
	raw[17] = (root_length)>> 8;
	//E131_ROOT_VECTOR
	for (int i = 0; i < 4; i++)
		raw[i+18] = _E131_ROOT_VECTOR[i];
	//E131_CID
	for (int i = 0; i < 4; i++)
		raw[i + 22] = _E131_ROOT_CID[i];

	// set Framing Layer values
	//frame.flength
	raw[38] = (0x70 | ((frame_length) & 0xFF));
	raw[39] = (frame_length) >> 8;

	//frame.vector
	for (int i = 0; i < 4; i++)
		raw[i + 40] = _E131_FRAME_VECTOR[i];

	// frame source name
	for (int i = 0; i < 64; i++)
		raw[i + 44] = 0x00;
	// frame priority
	raw[108] = E131_DEFAULT_PRIORITY;
	//synchronization adress
	raw[109] = 0x00;
	raw[110] = 0x00;
	//Sequence number
	raw[111] = 0x00;
	//frame option
	raw[112] = _E131_FRAME_OPTIONS;

	// frame universe
	raw[113] =  ((universe) & 0xFF);
	raw[114] = (universe) >> 8;


	// set Device Management Protocol (DMP) Layer values
	//dmp.flength
	raw[115] = (0x70 | ((dmp_length) & 0xFF));
	raw[116] = (dmp_length) >> 8;

	//_E131_DMP_VECTOR
	raw[117] = _E131_DMP_VECTOR;
	//_E131_DMP_TYPE
	raw[118]  = _E131_DMP_TYPE;

	//_E131_DMP_FIRST_ADDR
	raw[119] =  (_E131_DMP_FIRST_ADDR) & 0xFF;
	raw[120] = (_E131_DMP_FIRST_ADDR) >> 8;
	//_E131_DMP_ADDR_INC
	raw[121] = (_E131_DMP_ADDR_INC) & 0xFF;
	raw[122] = (_E131_DMP_ADDR_INC) >> 8;

	//prop_val_cnt
	raw[123] = (prop_val_cnt) & 0xFF;
	raw[124] = (prop_val_cnt) >> 8;
	// start code
	raw[125] = 0x00;
	return 0;
}


uint16_t Sacn::swapf_uint16(uint16_t x) {
	// return ( ( (x) <<8) | (( (x) >>8)&0xFF ) );
	return ((x));
}

uint32_t Sacn::swapf_uint32(uint32_t x) {
	return ((x));
}
Sacn::Sacn(QObject *parent) :
	QObject(parent)
{
	// create a QUDP socket
	socket = new QUdpSocket(this);

	// The most common way to use QUdpSocket class is
	// to bind to an address and port using bind()
	// bool QAbstractSocket::bind(const QHostAddress & address,
	//     quint16 port = 0, BindMode mode = DefaultForPlatform)
	socket->bind(QHostAddress("2.0.0.5"), 5568);

	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}
/*
void Sacn::UDP(int g) {

	static int v = 0;

		unsigned char  sACN_MSK_HEADER_E1_31[] = { 0x00,0x01,0x00, 0x00, 0x41, 0x53, 0x43, 0x2D, 0x45, 0x31, 0x2E, 0x31, 0x37, 0x00, 0x00, 0x00 };
		for (int i = 0; i < SACN_MSK_HEADER_E1_31_NBR; i++) {
			Data.append((unsigned char)sACN_MSK_HEADER_E1_31[i]);
		}
		unsigned char sACN_MSK_FARMING_LAYER[] = { 0x72 ,0x6E,0x00,0x00,0x00,0x04,0xE8,0x8A,0x5D,0xFA,0xDB,0xC9,0x4C,0xFB,0xB5,0xAA,0x5E,0xDB,0x67,0x66,0x94,0x2C,0x72,0x58,0x00,0x00,0x00,0x02,0x73,0x41,0x43,0x4E,0x20,0x76,0x31,0x2E,0x30 };
		for (int i = 0; i < SACN_MSK_FARMING_LAYER_NBR; i++) {
			Data.append((unsigned char)sACN_MSK_FARMING_LAYER[i]);
		}

		for (int i = 0; i < SACN_MSK_SACN_NBR_0; i++) {
			Data.append((char)0x00);
		}
		unsigned char sACN_MSK_FARMING_LAYER_END[] = { 0x64,0x00,0x00,0x00,0x00,0x00,0x01,0x72,0x0B,0x02,0xA1,0x00,0x00,0x00,0x01,0x02,0x01 };
		for (int i = 0; i < 17; i++) {
			if (i == 6)
				Data.append((unsigned char)g);
			else if (i == 3)
				Data.append((unsigned char)v);
			else
				Data.append((unsigned char)sACN_MSK_FARMING_LAYER_END[i]);
		}
		Data.append((char)0x00);
		for (int i = 0; i < 512; i++) {
			if (i < 8)
				Data.append((char)0xFF);

			else
				Data.append((char)0xFF);
		}

		if (g==8)
		v++;
		if (v == 255)
			v = 0;


}*/



void Sacn::HelloUDP()
{
	int num_channels = 512;
	int universe = 1;
	// compute packet layer lengths
	uint16_t prop_val_cnt = num_channels + 1;
	uint16_t dmp_length = prop_val_cnt +sizeof pwbuffTX->packed.dmp - sizeof pwbuffTX->packed.dmp.prop_val;
	uint16_t frame_length = sizeof pwbuffTX->packed.frame + dmp_length;
	uint16_t root_length = sizeof pwbuffTX->packed.root.flength + sizeof pwbuffTX->packed.root.vector + sizeof pwbuffTX->packed.root.cid + frame_length;

	// clear packet


	// set Root Layer values
	//preamble_size
	raw[0] = 0x00;
	raw[1] = 0x10;

	//postamble_size
	raw[2] = 0x00;
	raw[3] = 0x00;

	//_E131_ACN_PID
	for (int i = 0; i < 12; i++)
		raw[i + 4] = _E131_ACN_PID[i];

	//root.flength

	raw[16] = (0x70 | ((root_length) & 0xFF));
	raw[17] = (root_length) >> 8;
	//E131_ROOT_VECTOR
	for (int i = 0; i < 4; i++)
		raw[i + 18] = _E131_ROOT_VECTOR[i];
	//E131_CID
	for (int i = 0; i < 16; i++)
		raw[i + 22] = _E131_ROOT_CID[i];

	// set Framing Layer values
	//frame.flength
	raw[38] =(0x70 | ((frame_length) & 0xFF));
	raw[39] = (frame_length) >> 8;

	//frame.vector
	for (int i = 0; i < 4; i++)
		raw[i + 40] = _E131_FRAME_VECTOR[i];

	// frame source name
	raw[ 44] = 0x58;
	raw[ 45] = 0xA6;
	raw[46] = 0xFE;
	for (int i = 0; i < 61; i++)
		raw[i + 47] = 0x00;
	// frame priority
	raw[108] = E131_DEFAULT_PRIORITY;
	//synchronization adress
	raw[109] = 0x00;
	raw[110] = 0x00;
	//Sequence number
	raw[111] = 0x00;
	//frame option
	raw[112] = _E131_FRAME_OPTIONS;

	// frame universe
	raw[113] = 0x00; ((universe) & 0xFF);
	raw[114] = 0x08; (universe) >> 8;


	// set Device Management Protocol (DMP) Layer values
	//dmp.flength
	raw[115] = 0x72;//(0x70 | ((dmp_length) & 0xFF));
		raw[116] = 0x0b;//(dmp_length) >> 8;

	//_E131_DMP_VECTOR
	raw[117] = _E131_DMP_VECTOR;
	//_E131_DMP_TYPE
	raw[118] = _E131_DMP_TYPE;

	//_E131_DMP_FIRST_ADDR
	raw[119] = 0x00; //(_E131_DMP_FIRST_ADDR) & 0xFF;
	raw[120] = 0x00; //(_E131_DMP_FIRST_ADDR) >> 8;
	//_E131_DMP_ADDR_INC
	raw[121] = 0x00; //(_E131_DMP_ADDR_INC) & 0xFF;
		raw[122] = 0x01;//(_E131_DMP_ADDR_INC) >> 8;

		//prop_val_cnt
		raw[123] = 0x02; //(prop_val_cnt) & 0xFF;
		raw[124] = 0x01; //(prop_val_cnt) >> 8;
	// start code
	raw[125] = 0x00;

	for (int i = 126; i < 638; i++) {
		if (i < 135) {
			raw[i] = 0x00;
		}
		else{
			raw[i] = 0x00;
		}
	}
	for (int i = 0; i < 638; i++) {
		Data.append(raw[i]);
	}
	int g = 1;
	while (1) {

			// Sends the datagram datagram
			// to the host address and at port.
			// qint64 QUdpSocket::writeDatagram(const QByteArray & datagram,
			//                      const QHostAddress & host, quint16 port)
		raw[114] = 1;
		for (int i = 0; i < 638; i++) {
			Data.append(raw[i]);
		}
			socket->writeDatagram(Data, QHostAddress("239.255.0.1"), 5568);
			raw[114]++;
			g++;
			Data.clear();
			for (int i = 0; i < 638; i++) {
				Data.append(raw[i]);
			}
			socket->writeDatagram(Data, QHostAddress("239.255.0.2"), 5568);
			raw[114]++;
			g++;
			Data.clear();
			for (int i = 0; i < 638; i++) {
				Data.append(raw[i]);
			}
			socket->writeDatagram(Data, QHostAddress("239.255.0.3"), 5568);
			raw[114]++;
			g++;
			Data.clear();
			for (int i = 0; i < 638; i++) {
				Data.append(raw[i]);
			}
			socket->writeDatagram(Data, QHostAddress("239.255.0.4"), 5568);
			raw[114]++;
			g++;
			Data.clear();
			for (int i = 0; i < 638; i++) {
				Data.append(raw[i]);
			}
			socket->writeDatagram(Data, QHostAddress("239.255.0.5"), 5568);
			raw[114]++;
			g++;
			Data.clear();
			for (int i = 0; i < 638; i++) {
				Data.append(raw[i]);
			}
			socket->writeDatagram(Data, QHostAddress("239.255.0.6"), 5568);
			raw[114]++;
			g++;
			Data.clear();
			for (int i = 0; i < 638; i++) {
				Data.append(raw[i]);
			}
			socket->writeDatagram(Data, QHostAddress("239.255.0.7"), 5568);
			raw[114]++;
			g++;
			Data.clear();
			for (int i = 0; i < 638; i++) {
				Data.append(raw[i]);
			}
			socket->writeDatagram(Data, QHostAddress("239.255.0.8"), 5568);
			raw[114]++;
			
			Data.clear();
			
			 
				
				raw[114]=1;
			


		}
	}


void Sacn::readyRead()
{
	// when data comes in
	QByteArray buffer;
	buffer.resize(socket->pendingDatagramSize());

	QHostAddress sender;
	quint16 senderPort;

	// qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
	//                 QHostAddress * address = 0, quint16 * port = 0)
	// Receives a datagram no larger than maxSize bytes and stores it in data.
	// The sender's host address and port is stored in *address and *port
	// (unless the pointers are 0).

	socket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

	qDebug() << "Message from: " << sender.toString();
	qDebug() << "Message port: " << senderPort;
	qDebug() << "Message: " << buffer;
}
// ─────────────────────────────────────────────────────────────
//					FUNCTIONS
// ─────────────────────────────────────────────────────────────
