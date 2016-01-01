#include <wiringPi.h>
#include "PinData.hpp"

class GBLink {
	public:
		void initSlave(PinData& pinData);
		
		void sendClock(PinData& pinData);
		void sendByte(uint8_t send, PinData& pinData);
};
