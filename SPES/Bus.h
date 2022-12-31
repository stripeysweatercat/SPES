#pragma once
#include "cpu65816.h"


class Bus
{
public:
	Bus();
	~Bus();

public: // Devices connected to bs
	// CPU (obviously xp)
	cpu65816 cpu;

public:
	void	 cpuWrite(uint32_t addr, uint16_t data);
	uint16_t cpuRead(uint16_t data, bool readOnly = false);

private:
	// Count of system clocks passed
	uint32_t systemClockCounter = 0;
};