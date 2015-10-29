#include <wiringPi.h>

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
};
