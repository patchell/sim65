#include "pch.h"

CPeripheral::CPeripheral()
{
}

CPeripheral::~CPeripheral()
{
}

BOOL CPeripheral::Create(PeriphType Type)
{
	BOOL rV = TRUE;

	m_PeripheralType = Type;
	return rV;
}
