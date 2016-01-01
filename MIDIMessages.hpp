#pragma once
namespace MIDI {
	enum Message {
		CLOCK = 0xF8,
		START = 0xFA,
		CONTINUE = 0xFB,
		STOP = 0xFC,
		SONGPOSPTR = 0xF2
	};
}