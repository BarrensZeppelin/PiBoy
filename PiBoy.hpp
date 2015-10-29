#include <wiringPi.h>
#include "SerialMIDI.hpp"
#include "GBLink.hpp"

class Mode;

class PiBoy {
	private:
		Mode* mode;
	
		SerialMIDI serial;
		GBLink gblink;

	public:
		PiBoy();
		~PiBoy();

		int run();
};
