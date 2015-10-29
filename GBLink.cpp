#include "GBLink.hpp"

GBLink::GBLink() {
	for(int i = 0; i < 3; i++)
		pinMode(i, OUTPUT);

	digitalWrite(Pin::Clock, 1);
	digitalWrite(Pin::Write, 0);
}

void GBLink::initSlave() {
	for(int i = 0; i < 3; i++)
		pinMode(i, OUTPUT);

	digitalWrite(Pin::Clock, 1);
}

void GBLink::sendClock() {
	for(int i = 0; i < 8; i++) {
		digitalWrite(Pin::Clock, 0);
		digitalWrite(Pin::Clock, 1);
	}
}
