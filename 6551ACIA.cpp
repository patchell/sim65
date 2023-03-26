#include "pch.h"

C6551ACIA::C6551ACIA()
{
}

C6551ACIA::~C6551ACIA()
{
}

BOOL C6551ACIA::Create()
{
	BOOL rV = TRUE;

	rV = CPeripheral::Create(CPeripheral::PeriphType::ACIA6551);
	return rV;
}
