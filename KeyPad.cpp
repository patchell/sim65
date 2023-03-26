#include "pch.h"

CKeyPad::CKeyPad()
{
}

CKeyPad::~CKeyPad()
{
}

BOOL CKeyPad::Create()
{
	BOOL rV = TRUE;

	rV = CPeripheral::Create(CPeripheral::PeriphType::KEYPAD);
	return rV;
}
