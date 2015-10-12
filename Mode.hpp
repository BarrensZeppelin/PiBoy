#pragma once

class SerialMIDI;

class Mode {
	protected:
		SerialMIDI& serial;
	
	public:
		Mode(SerialMIDI& s);

		virtual void tick() = 0;
};
