#include "pch.h"

CMemory::CMemory()
{
	m_pData = 0;
	m_Size = 0;
	m_StartAddress = 0;
}

CMemory::~CMemory()
{
	if (m_pData)
		delete[] m_pData;
}

BOOL CMemory::Create(UINT Address, UINT Size)
{
	BOOL rV = TRUE;;

	m_Size = Size;
	m_StartAddress = Address;
	m_pData = new UCHAR[Size];
	rV = CPeripheral::Create(CPeripheral::PeriphType::MEMORY);
	return rV;
}

UCHAR CMemory::GetData(UINT Address)
{
	return m_pData[Address - m_StartAddress];;
}

void CMemory::SetData(UINT Address, UCHAR Data)
{
	m_pData[Address - m_StartAddress] = Data;
}
