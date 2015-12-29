#include <wiringPi.h>
#include "SerialMIDI.hpp"
#include "GBLink.hpp"
#include <vector>

class Mode;

class PiBoy {
	private:
		std::vector<Mode*> modes;
	
		SerialMIDI serial;
		GBLink gblink;

	public:
		PiBoy();
		~PiBoy();

		int run();
};
