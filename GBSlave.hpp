#pragma once
#include "Mode.hpp"
#include "PinData.hpp"

class GBLink;

class GBSlave : public Mode {
protected:
    GBLink& gblink;
    PinData pinData;

public:
    GBSlave(GBLink& gb, PinData data);
};