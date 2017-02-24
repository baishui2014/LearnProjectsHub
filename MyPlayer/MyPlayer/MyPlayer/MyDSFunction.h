#pragma once
//定义了Directshow里面一些常用的方法

#include <DShow.h>

class CMyDSFunction
{
private:
	CMyDSFunction();
	~CMyDSFunction();
public:
	static void AddToROT(IGraphBuilder* pGraph,DWORD *pEntry);//将一个IGraphBuilder*加入running object table,以便graphedt.exe查看
	static void RemoveFromROT(DWORD *pEntry);//从running object table里面删除dwEntry对应的
};