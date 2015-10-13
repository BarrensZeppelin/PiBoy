#include "GBLink.hpp"


const short GBLink::GBPins[3] = {0, 1, 2};

void GBLink::sendClock() {
	for(int i = 0; i < 8; i++) {
		digitalWrite(GBPins[0], 0);
		digitalWrite(GBPins[0], 1);
	}
}
