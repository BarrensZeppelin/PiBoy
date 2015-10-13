#pragma once

class SerialMIDI;
class GBLink;

class Mode {
	private:
		bool started;

	protected:
		SerialMIDI& serial;
		GBLink& gblink;

	public:
		Mode(SerialMIDI& s, GBLink& gb);

		virtual void tick() = 0;

		void start();
		void stop();
		bool isStarted();

};
