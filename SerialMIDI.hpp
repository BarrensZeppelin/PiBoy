#include "wiringPi/wiringPi/wiringSerial.h"
#include <String>
#include <cstdint>

using namespace std;


class SerialMIDI {
	private:
		static const int baudrate;
		static const string device;
		
		int ser;
		
	public:
		SerialMIDI();
		~SerialMIDI();
		
		void sendByte(uint8_t b);
};