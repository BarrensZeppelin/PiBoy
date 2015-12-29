#pragma once
#include <PinData.hpp>

class SerialMIDI;
class GBLink;

class Mode {
	private:
		bool started;

	protected:
		SerialMIDI& serial;
		GBLink& gblink;
		PinData pinData;

	public:
		Mode(SerialMIDI& s, GBLink& gb, PinData data);

		virtual void handleStatusByte(uint8_t b) = 0;
		virtual void handleDataByte(uint8_t b) = 0;
		virtual void tick() = 0;

		void start();
		void stop();
		bool isStarted();

};
