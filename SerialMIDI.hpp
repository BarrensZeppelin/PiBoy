#pragma once

#include <wiringSerial.h>
#include <string>
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
		
		bool dataAvailable();

		void sendByte(uint8_t b);
		void sendString(string s);

		uint8_t readByte();
		string readString();
};
