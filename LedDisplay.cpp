#include "pch.h"

CLedDisplay::CLedDisplay()
{
}

CLedDisplay::~CLedDisplay()
{
}

BOOL CLedDisplay::Create()
{
	BOOL rV = TRUE;

	rV = CPeripheral::Create(CPeripheral::PeriphType::LEDDISPLAY);
	return rV;
}
