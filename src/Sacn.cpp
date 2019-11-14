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
//#include <Windows.h>
#include <stdint.h>
//#include <Winsock.h>
#include "Effects.hpp"


// ─────────────────────────────────────────────────────────────
//					DECLARATION
// ─────────────────────────────────────────────────────────────

FOYLIGHT_USING_NAMESPACE;

// ─────────────────────────────────────────────────────────────
//					FUNCTIONS
// ─────────────────────────────────────────────────────────────


int Sacn::setPacketHeader(const uint16_t universe, const uint16_t num_channels) {

	// compute packet layer lengths
	uint16_t prop_val_cnt = num_channels + 1;
	uint16_t dmp_length = prop_val_cnt + 9 * sizeof(uint8_t);
	uint16_t frame_length = 7 * sizeof(uint16_t) + dmp_length;
	uint16_t root_length = 22 * sizeof (uint8_t) + frame_length;

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
	raw[38] = (0x70 | ((frame_length) & 0xFF));
	raw[39] = (frame_length) >> 8;

	//frame.vector
	for (int i = 0; i < 4; i++)
		raw[i + 40] = _E131_FRAME_VECTOR[i];

	// frame source name
	raw[44] = 0x58;
	raw[45] = 0xA6;
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
	raw[113] = 0x00;
	raw[114] = 0x08;


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

	return 0;
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
	#ifdef ANDROID
	 socket->bind(QHostAddress("172.24.1.1"), E131_DEFAULT_PORT_srv);

#else
    socket->bind(QHostAddress("2.0.0.2"), E131_DEFAULT_PORT_srv);
#endif



}

void Sacn::SendSacn(FixtureList *f)
{

		setPacketHeader(1, 512);
		//parLedGroupeEffects(f, Sin, 0,parUn,lineaire);
		//parLedGroupeEffects(f, Raimbow, 0, tous, lineaire);
		int v[512] = { 0 };

		for (auto it : *f) {
			uint8_t * fixture = (uint8_t*)malloc(sizeof(uint8_t)*it->getNumberChannel());
			it->sendData(fixture);
			for (int i = 125 + it->getChannel(); i < 125 + it->getChannel()+ it->getNumberChannel()+1 && i<638; i++) {
				raw[i] = fixture[i - (125 + it->getChannel())];
				v[i- 125] = 1;
			}
			free(fixture);
		}
		for (int i = 0; i < 512; i++)
		{
			if(v[i]==0)
			raw[i+125] = 0x00;
		}



		/*for (int i = 0; i < 638; i++) {
			Data.append(raw[i]);
		}*/
		int g = 1;


		// Sends the datagram datagram
		// to the host address and at port.
		// qint64 QUdpSocket::writeDatagram(const QByteArray & datagram,
		//                      const QHostAddress & host, quint16 port)
		raw[114] = 1;
		for (int i = 0; i < 638; i++) {
			Data.append(raw[i]);
		}
		socket->writeDatagram(Data, QHostAddress("239.255.0.1"), E131_DEFAULT_PORT_srv);
		raw[114]++;
		g++;
		Data.clear();
		for (int i = 0; i < 638; i++) {
			Data.append(raw[i]);
		}
		socket->writeDatagram(Data, QHostAddress("239.255.0.2"), E131_DEFAULT_PORT_srv);
		raw[114]++;
		g++;
		Data.clear();


		raw[114] = 1;




	}


