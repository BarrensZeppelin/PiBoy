#include "Mode.hpp"

Mode::Mode(SerialMIDI& s, GBLink& gb) : serial(s), gblink(gb), started(false) {
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
