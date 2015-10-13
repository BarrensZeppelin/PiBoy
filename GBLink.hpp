#include <wiringPi.h>

class GBLink {
	public:
		static const short GBPins[3];

	public:
		void sendClock();
};
