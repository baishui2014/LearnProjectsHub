#pragma once
//������Directshow����һЩ���õķ���

#include <DShow.h>

class CMyDSFunction
{
private:
	CMyDSFunction();
	~CMyDSFunction();
public:
	static void AddToROT(IGraphBuilder* pGraph,DWORD *pEntry);//��һ��IGraphBuilder*����running object table,�Ա�graphedt.exe�鿴
	static void RemoveFromROT(DWORD *pEntry);//��running object table����ɾ��dwEntry��Ӧ��
};