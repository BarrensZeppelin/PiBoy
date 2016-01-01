#include "Mode.hpp"

Mode::Mode(SerialMIDI& s, GBLink& gb, PinData data) : serial(s), gblink(gb), started(true), pinData(data) { // true for testing
}


void Mode::start() {
	started = true;
}

void Mode::stop() {
	started = false;
}

bool Mode::isStarted() {
	return started;
}
