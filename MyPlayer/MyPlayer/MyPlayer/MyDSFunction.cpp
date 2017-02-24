#include "stdafx.h"

#include "MyDSFunction.h"

CMyDSFunction::CMyDSFunction()
{

}

CMyDSFunction::~CMyDSFunction()
{

}

void CMyDSFunction::AddToROT(IGraphBuilder* pGraph,DWORD *pEntry)
{
	if(!pGraph || !pEntry) return;
	IMoniker *pMoniker = NULL;
	IRunningObjectTable *pObjTable = NULL;
	if (SUCCEEDED(GetRunningObjectTable(0,&pObjTable)))
	{
		WCHAR wsz[256] = {0};
		swprintf_s(wsz,256,L"FilterGraph %08p pid %08x",(DWORD_PTR)pGraph,GetCurrentProcessId());
		HRESULT hr = CreateItemMoniker(L"!",wsz,&pMoniker);
		if (SUCCEEDED(hr))
		{
			pObjTable->Register(0,pGraph,pMoniker,pEntry);
			pMoniker->Release();
		}
		pObjTable->Release();
	}
}

void CMyDSFunction::RemoveFromROT(DWORD *pEntry)
{
	if(!pEntry) return;
	IMoniker *pMoniker = NULL;
	IRunningObjectTable *pObjTable = NULL;
	if (SUCCEEDED(GetRunningObjectTable(0,&pObjTable)))
	{
		pObjTable->Revoke(*pEntry);
		pObjTable->Release();
		*pEntry = 0;
	}
}