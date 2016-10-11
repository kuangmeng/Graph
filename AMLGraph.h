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
	int mark;//��־��ָʾ�ñ��Ƿ񱻷��ʹ�(0:û��1:��) 
	int ivex, jvex;//�ñ߹��������������λ�� 
	EBox *ilink, *jlink;//�ֱ�ָ������������������һ���� 
};
//������ 
struct VexBox
{
	int data;  //�������� 
	EBox *firstedge;//ָ���һ�������ý��ı� 
};
class AMLGraph
{
public:
	VexBox adjmulist[NUM]; //��������ָ�� 
	int n,e; 
	int edge[NUM][2];
	//��λ�����ڶ��������е�λ�� 
	int LocateVex(int v)
	{
		for (int i = 0; i<n; i++)
			if (adjmulist[i].data == v)
				return i;
		return -1;
	}
	//�ڽӶ��ر�������ͼ
	void CreateAMLGraph()
	{ 
		int v1, v2;
		int i, j, k;
		cout << "���붥����Ŀ�ͱߵ���Ŀ��";
		cin >> n >> e;
		for (i = 0; i<n; i++)
		{
			printf("�������%d�����㣺", i + 1);
			cin >> adjmulist[i].data;
			adjmulist[i].firstedge = NULL;
		}
		for (k = 0; k<e; k++)
		{
			printf("�������%d���ߣ�", k + 1);
			cin >> v1 >> v2;
			while (Search(v1, v2))
			{
				cout << "�ñ��Ѵ��ڣ���ͼ��֧�ִ���ƽ�б�!" << endl;
				cout << "��������ߵ��������㣺";
				cin >> v1 >> v2;
			}
			i = LocateVex(v1);
			j = LocateVex(v2);
			while (i == -1 || j == -1)
			{
				cout << "�����������в�����Ҫ��ģ����������룺";
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
		cout << "�ڽӶ��ر�����ͼ��ɣ�" << endl;
	}
	//������Ӧ�ı��Ƿ���� 
bool Search(int v1, int v2)
	{
		int i, j;
		EBox *p;
		i = LocateVex(v1);
		j = LocateVex(v2);
		if (i == -1 || j == -1)
		{
			cout << "������󣬸ñ߲����ڣ�" << endl;
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
	//������ȱ��� 
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
	//������ȷǵݹ���� 
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
	//������ȱ��� 
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
	//�ñߵķ��ʱ�־Ϊδ���� 
	void Mark();
	//����ڽӶ��ر� 
	void Display();
	//���ļ���ʽ���뽨����ͼ�ĳ���
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
	cout << "����ͼ����ֱ�Ϊ��";
	for (i = 0; i<n; i++)
		cout << adjmulist[i].data << "  ";
	cout << endl;
	cout << "�ܹ���" << e << "���ߡ�" << endl;
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