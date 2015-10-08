#include "wiringPi/wiringPi/wiringPi.h"
class Mode;

class PiBoy {
	private:
		Mode* mode;
		bool started;
	
	public:
		PiBoy();
		
		int run();
};