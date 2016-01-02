#pragma once
namespace MIDI {
	enum SystemMessage {
		CLOCK = 0xF8,
		START = 0xFA,
		CONTINUE = 0xFB,
		STOP = 0xFC,
		SONGPOSPTR = 0xF2
	};

	enum ChannelMessage {
		NOTEOFF = 0x8,
		NOTEON = 0x9,
		CONTROLCHANGE = 0xB
	};
}
