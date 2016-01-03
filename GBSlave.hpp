#pragma once
#include "Slave.hpp"
#include "PinData.hpp"

class GBLink;

class GBSlave : public Slave {
protected:
    GBLink& gblink;
    PinData pinData;

public:
    GBSlave(GBLink& gb, PinData data);
};