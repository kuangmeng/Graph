#pragma once
#ifndef AMLGraph_h 
#define AMLGraph_h 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "MakeQueue.h"
using namespace std;
struct EBox
{
	int mark;//标志域，指示该边是否被访问过(0:没有1:有) 
	int ivex, jvex;//该边关联的两个顶点的位置 
	EBox *ilink, *jlink;//分别指向关联这两个顶点的下一条边 
};
//顶点结点 
struct VexBox
{
	int data;  //顶点名称 
	EBox *firstedge;//指向第一条关联该结点的边 
};
class AMLGraph
{
public:
	VexBox adjmulist[NUM]; //顶点数组指针 
	int n,e; 
	int edge[NUM][2];
	//定位顶点在顶点数组中的位置 
	int LocateVex(int v)
	{
		for (int i = 0; i<n; i++)
			if (adjmulist[i].data == v)
				return i;
		return -1;
	}
	//邻接多重表建立无向图
	void CreateAMLGraph()
	{ 
		int v1, v2;
		int i, j, k;
		cout << "输入顶点数目和边的数目：";
		cin >> n >> e;
		for (i = 0; i<n; i++)
		{
			printf("请输入第%d个顶点：", i + 1);
			cin >> adjmulist[i].data;
			adjmulist[i].firstedge = NULL;
		}
		for (k = 0; k<e; k++)
		{
			printf("请输入第%d条边：", k + 1);
			cin >> v1 >> v2;
			while (Search(v1, v2))
			{
				cout << "该边已存在，本图不支持存在平行边!" << endl;
				cout << "重新输入边的两个顶点：";
				cin >> v1 >> v2;
			}
			i = LocateVex(v1);
			j = LocateVex(v2);
			while (i == -1 || j == -1)
			{
				cout << "两个顶点中有不符合要求的，请重新输入：";
				cin >> v1 >> v2;
				i = LocateVex(v1);
				j = LocateVex(v2);
			} 
			edge[k][0] = i;
			edge[k][1] = j;
			EBox *p = new EBox;
			p->ivex = i;
			p->jvex = j;
			p->ilink = adjmulist[i].firstedge;
			p->jlink = adjmulist[j].firstedge;
			adjmulist[i].firstedge = adjmulist[j].firstedge = p;
		}
		cout << "邻接多重表建无向图完成！" << endl;
	}
	//搜索对应的边是否存在 
bool Search(int v1, int v2)
	{
		int i, j;
		EBox *p;
		i = LocateVex(v1);
		j = LocateVex(v2);
		if (i == -1 || j == -1)
		{
			cout << "顶点错误，该边不存在！" << endl;
			return false;
		}
		p = adjmulist[i].firstedge;
		while (p)
		{
			if (p->ivex == i && p->jvex == j)
				return true;
			else if (p->jvex == i && p->ivex == j)
				return true;
			else if (p->ivex == i)
				p = p->ilink;
			else if (p->jvex == i)
				p = p->jlink;
		}
		return false;
	}
	//深度优先遍历 
	void DFS_Traverse()
	{
		for (int i = 0; i<n; i++)
			visit[i] = 0;
		for (int i = 0; i<n; i++)
			if (!visit[i])
				DFS(i);
		cout << endl;
	}
	void DFS(int v)
	{
		visit[v] = 1;
		cout << adjmulist[v].data << "  ";
		EBox *p = adjmulist[v].firstedge;
		while (p)
		{
			if (p->ivex == v)
			{
				if (!visit[p->jvex])
					DFS(p->jvex);
				p = p->ilink;
			}
			else
			{
				if (!visit[p->ivex])
					DFS(p->ivex);
				p = p->jlink;
			}
		}
	}
	//深度优先非递归遍历 
	void DFS_Traverse2()
	{
		for (int i = 0; i<n; i++)
			visit[i] = 0;
		for (int i = 0; i<n; i++)
			if (!visit[i])
				DFS2(i);
		cout << endl;
	}
	void DFS2(int v)
	{
		visit[v] = 1;
		cout << adjmulist[v].data << "  ";
		EBox *p = adjmulist[v].firstedge;
		while (p)
		{
			if (p->ivex == v)
			{
				if (!visit[p->jvex]) {
					visit[p->jvex] = 1;
					cout << adjmulist[p->jvex].data << "  ";
				}
				p = p->ilink;
			}
			else
			{
				if (!visit[p->ivex]) {
					visit[p->ivex] = 1;
					cout << adjmulist[p->ivex].data << "  ";
				}
				p = p->jlink;
			}
		}
	}
	//广度优先遍历 
	void BFS_Traverse()
	{
		for (int i = 0; i<n; i++)
			visit[i] = 0;
		for (int i = 0; i<n; i++)
			if (!visit[i])
				BFS(i);
		cout << endl;
	}
	void BFS(int v)
	{
		visit[v] =1;
		cout << adjmulist[v].data << "  ";
		EBox *p;
		int i;
		LinkQueue Q;
		InitQueue(&Q);
		EnQueue(&Q, v);
		while (!QueueEmpty(Q))
		{
			DeQueue(&Q, &i);
			p = adjmulist[i].firstedge;
			while (p)
			{
				if (p->ivex == i)
				{
					if (!visit[p->jvex])
					{
						visit[p->jvex] = 1;
						cout << adjmulist[p->jvex].data << "  ";
						EnQueue(&Q, p->jvex);
					}
					p = p->ilink;
				}
				else
				{
					if (!visit[p->ivex])
					{
						visit[p->ivex] = 1;
						cout << adjmulist[p->ivex].data << "  ";
						EnQueue(&Q,p->ivex);
					}
					p = p->jlink;
				}
			}
		}
	}
	//置边的访问标志为未访问 
	void Mark();
	//输出邻接多重表 
	void Display();
	//以文件形式输入建无向图的程序
	void CreateAMLGraph2();
};
void AMLGraph:: Mark()
{
	int i;
	EBox *p;
	for (i = 0; i<n; i++)
	{
		p = adjmulist[i].firstedge;
		while (p)
		{
			p->mark = 0;
			if (p->ivex == i)
				p = p->ilink;
			else
				p = p->jlink;
		}
	}
}
void AMLGraph:: Display()
{
	int i;
	EBox *p;
	Mark();
	cout << "无向图顶点分别为：";
	for (i = 0; i<n; i++)
		cout << adjmulist[i].data << "  ";
	cout << endl;
	cout << "总共有" << e << "条边。" << endl;
	for (i = 0; i<n; i++)
	{
		p = adjmulist[i].firstedge;
		while (p)
		{
			if (p->ivex == i)
			{
				if (!p->mark)
				{
					cout << adjmulist[i].data << "--" << adjmulist[p->jvex].data << endl;
					p->mark = 1;
				}
				p = p->ilink;
			}
			else
			{
				if (!p->mark)
				{
					cout << adjmulist[p->jvex].data << "--" << adjmulist[p->ivex].data << endl;
					p->mark = 1;
				}
				p = p->jlink;
			}
		}
	}
}
#endif