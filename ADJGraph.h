#pragma once
#ifndef ADJGraph_h
#define ADJGraph_h
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "MakeQueue.h"
//�ڽӱ�Ĵ洢�ṹ����
typedef int VertexData;
typedef struct node {    /*��ڵ�*/
	int adjvex;      /*�ڽӵ�*/
	struct node *next;   /*ָ����һ������ָ��*/
}EdgeNode;
typedef struct {   /*ͷ���*/
	VertexData vertex;      /*������Ϣ*/
	EdgeNode * firstedge;     /*ָ���һ�������ö���Ļ���ָ��*/
}VertexNode;
typedef struct {    /*ͼ*/
	VertexNode verlist[NUM];   /*��*/
	int n, e;  /*ͼ�Ķ������ͻ���*/
	int edge[NUM][2];
}ADJGraph;
int T = 1;
//����ͼ�ڽӱ�Ľ���
int LocateVex(ADJGraph * G, int i) /*Ѱ�ҽڵ�V��λ��*/
{
	for (int k = 0; k<G->n; k++) {
		if (G->verlist[k].vertex == i) {
			T = k;
			break;
		}
	}
	return T;
}
//������ȱ���
void DFS(ADJGraph *G, int i)
{
	EdgeNode *p;
	cout << "  " << G->verlist[i].vertex << "  ";
	p = G->verlist[i].firstedge;
	visit[i] = 1;
	while (p) {
		if (!visit[p->adjvex]) {
			DFS(G,p->adjvex);
		}
		p = p->next;
	}
}
void DFSVisited(ADJGraph * G)
{
	int v;
	for (v = 0; v < G->n; v++) {
		visit[v] = 0;
	}
	for (v = 0; v < G->n; v++) {
		if (!visit[v]) DFS(G, v);
	}
}
//������ȷǵݹ�
void DFS2(ADJGraph *G, int i)
{
	EdgeNode *p;
	cout << "  " << G->verlist[i].vertex << "  ";
	p = G->verlist[i].firstedge;
	visit[i] = 1;
	while (p) {
		if (!visit[p->adjvex]) {
			cout << "  " << G->verlist[p->adjvex].vertex << "  ";
			visit[p->adjvex] = 1;
		}
		p = p->next;
	}
}
void DFSVisited2(ADJGraph * G)
{
	int v;
	for (v = 0; v < G->n; v++) { 
		visit[v] = 0; 
	}
	for (v = 0; v < G->n; v++) {
		if (!visit[v]) DFS2(G, v);
	}
}
//��ӡ�ڽӱ�
void PrintADJGraph(ADJGraph *G) 
{
	EdgeNode *p;
	for (int i = 0; i<G->n; i++) {
		cout << i << " | " << G->verlist[i].vertex;
		if (G->verlist[i].firstedge != NULL) {
			p = G->verlist[i].firstedge;
			while (p)
			{
				cout << "-->" << p->adjvex;
				p = p->next;
			}
		}
		cout << endl;
	}
}
void Insert(ADJGraph * G, int i, int j)  /*�����ڽӵ���±�*/
{
	EdgeNode *a1, *a2;
	a1 = (EdgeNode *)malloc(sizeof(EdgeNode));
	a1->adjvex = j; a1->next = NULL;
	if (G->verlist[i].firstedge == NULL) {
		G->verlist[i].firstedge = a1;
	}
	else {
		a2 = G->verlist[i].firstedge;
		while (a2->next)
		{
			a2 = a2->next;
		}
		a2->next = a1;
	}
}
//��ʼ��ͼ����ͼ
void CreateADJGraph(ADJGraph * G)
{
	int v, a1, a2, i, j;
	cout << "������ͼ�Ķ����������: ";
	cin >> G->n >> G->e;
	for (v = 0; v<G->n; v++) {
		printf("����� %d����:", (v + 1));
		cin >> G->verlist[v].vertex;
		G->verlist[v].firstedge = NULL;
	}
	for (v = 0; v<G->e; v++)
	{
		printf("�����%d����: ", (v + 1));
		cin >> a1 >> a2;
		i = LocateVex(G, a1);
		j = LocateVex(G, a2);
		while (i == -1 || j == -1)
		{
			cout << "�����������в�����Ҫ��ģ����������룺";
			cin >> a1 >> a2;
			i = LocateVex(G, a1);
			j = LocateVex(G, a2);
		}
		G->edge[v][0] = i;
		G->edge[v][1] = j;
		Insert(G, i, j);
		Insert(G, j, i);
	}
	cout << "���ڽӱ�����ͼ������" << endl;
}
//�ڽӱ��ȱ���
void BFSTraverse(ADJGraph *G)
{
	LinkQueue	Q;
	InitQueue(&Q); //��ʼ������  
	for (int i = 0; i < G->n; ++i) //������Ϊ����Ϊδ����  
		visit[i] = 0;
	for (int i = 0; i < G->n; ++i)
	{
		if (0 == visit[i]) //ѡȡһ��δ���ʵĶ���,���ͼ����ͨͼ,��ִֻ��һ��  
		{
			visit[i] = 1; //���ö���Ϊ�ѷ���  
			cout << G->verlist[i].vertex;
			EnQueue(&Q, i); //��ǰ������±�ֵ����  
			while (!QueueEmpty(Q)) //���в�Ϊ��  
			{
				DeQueue(&Q, &i); //����  
				EdgeNode *p = G->verlist[i].firstedge; //ָ����һ���߱���  
				while (p)
				{
					if (!visit[p->adjvex]) //�����δ���ʵĽ��  
					{
						visit[p->adjvex] = 1;
						cout << "  " << G->verlist[p->adjvex].vertex << "  ";
						EnQueue(&Q, p->adjvex);
					}
					p = p->next; //ָ����һ���߱���  
				}
			}
		}
	}
	cout << endl;
}
#endif