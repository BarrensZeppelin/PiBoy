#include <unistd.h>
#include <fstream>
#include "GBLink.hpp"

void GBLink::initSlave(PinData& pinData) {
	pinMode(pinData.read, OUTPUT);
	pinMode(pinData.write, OUTPUT);
	pinMode(pinData.clock, OUTPUT);

	digitalWrite(pinData.clock, 1);
	digitalWrite(pinData.write, 0);

	// I found that the Raspberry Pi 3 is a bit too fast,
	// so the clock signal is delayed a bit to compensate.
	std::ifstream modelFd("/proc/device-tree/model");
	std::string model(std::istreambuf_iterator<char>(modelFd), {});
	modelFd.close();
	clockDelay = (model.find("Raspberry Pi 3") !== std::string::npos ? 500 : 0);
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
		usleep(clockDelay);
		digitalWrite(pinData.clock, 1);
		usleep(clockDelay);

		send <<= 1;
	}
}
