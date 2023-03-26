#include "pch.h"

C6522VIA::C6522VIA()
{
}

C6522VIA::~C6522VIA()
{
}

BOOL C6522VIA::Create()
{
	BOOL rV = TRUE;

	rV = CPeripheral::Create(CPeripheral::PeriphType::VIA6522);
	return rV;
}
