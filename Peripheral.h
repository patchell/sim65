#pragma once

class CPeripheral
{
public:
	enum class PeriphType {
		ACIA6551,
		VIA6522,
		MEMORY,
		VECTORIRQ,
		KEYPAD,
		LEDDISPLAY,
		MOS6502,
		WD65C02,
		WD65816
	};
private:
	PeriphType m_PeripheralType;
public:
	CPeripheral();
	virtual ~CPeripheral();
	BOOL Create(PeriphType Type);
};

