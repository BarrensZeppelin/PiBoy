#include <wiringPi.h>
#include "SerialMIDI.hpp"

class Mode;

class PiBoy {
	private:
		Mode* mode;
		bool started;
	
		SerialMIDI serial;

	public:
		PiBoy();
		
		int run();
};
