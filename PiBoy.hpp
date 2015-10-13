#include <wiringPi.h>
#include "SerialMIDI.hpp"
#include "GBLink.hpp"

class Mode;

class PiBoy {
	private:
		Mode* mode;
		bool started;
	
		SerialMIDI serial;
		GBLink gblink;

	public:
		PiBoy();
		
		int run();
};
