#include <wiringPi.h>
#include <stdint.h>

class GBLink {
	public:
		enum Pin {
			Write,
			Clock,
			Read
		};

	public:
		GBLink();

		void initSlave();
		
		void sendClock();
		void sendByte(uint8_t send);
};
