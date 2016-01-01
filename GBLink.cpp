#include "GBLink.hpp"

void GBLink::initSlave(PinData& pinData) {
	pinMode(pinData.read, OUTPUT);
	pinMode(pinData.write, OUTPUT);
	pinMode(pinData.clock, OUTPUT);

	digitalWrite(pinData.clock, 1);
	digitalWrite(pinData.write, 0);
}

void GBLink::sendClock(PinData& pinData) {
	sendByte(0, pinData);
}


void GBLink::sendByte(uint8_t send, PinData& pinData) {
	for(int i = 0; i < 8; i++) {
		if(send & 0x80)
			digitalWrite(pinData.write, 1);
		else
			digitalWrite(pinData.write, 0);
		
		digitalWrite(pinData.clock, 0);
		digitalWrite(pinData.clock, 1);

		send <<= 1;
	}
}
