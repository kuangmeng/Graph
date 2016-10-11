#pragma once
#ifndef ADJGraph_h
#define ADJGraph_h
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "MakeQueue.h"
//邻接表的存储结构定义
typedef int VertexData;
typedef struct node {    /*表节点*/
	int adjvex;      /*邻接点*/
	struct node *next;   /*指向下一条弧的指针*/
}EdgeNode;
typedef struct {   /*头结点*/
	VertexData vertex;      /*定点信息*/
	EdgeNode * firstedge;     /*指向第一个依附该顶点的弧的指针*/
}VertexNode;
typedef struct {    /*图*/
	VertexNode verlist[NUM];   /*顶*/
	int n, e;  /*图的顶点数和弧数*/
	int edge[NUM][2];
}ADJGraph;
int T = 1;
//无向图邻接表的建立
int LocateVex(ADJGraph * G, int i) /*寻找节点V的位置*/
{
	for (int k = 0; k<G->n; k++) {
		if (G->verlist[k].vertex == i) {
			T = k;
			break;
		}
	}
	return T;
}
//深度优先遍历
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
//深度优先非递归
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
//打印邻接表
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
void Insert(ADJGraph * G, int i, int j)  /*插入邻接点的下标*/
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
//初始化图并建图
void CreateADJGraph(ADJGraph * G)
{
	int v, a1, a2, i, j;
	cout << "请输入图的顶点数与边数: ";
	cin >> G->n >> G->e;
	for (v = 0; v<G->n; v++) {
		printf("输入第 %d个点:", (v + 1));
		cin >> G->verlist[v].vertex;
		G->verlist[v].firstedge = NULL;
	}
	for (v = 0; v<G->e; v++)
	{
		printf("输入第%d条边: ", (v + 1));
		cin >> a1 >> a2;
		i = LocateVex(G, a1);
		j = LocateVex(G, a2);
		while (i == -1 || j == -1)
		{
			cout << "两个顶点中有不符合要求的，请重新输入：";
			cin >> a1 >> a2;
			i = LocateVex(G, a1);
			j = LocateVex(G, a2);
		}
		G->edge[v][0] = i;
		G->edge[v][1] = j;
		Insert(G, i, j);
		Insert(G, j, i);
	}
	cout << "用邻接表建无向图结束！" << endl;
}
//邻接表广度遍历
void BFSTraverse(ADJGraph *G)
{
	LinkQueue	Q;
	InitQueue(&Q); //初始化队列  
	for (int i = 0; i < G->n; ++i) //设置所为顶点为未访问  
		visit[i] = 0;
	for (int i = 0; i < G->n; ++i)
	{
		if (0 == visit[i]) //选取一个未访问的顶点,如果图是连通图,则只执行一次  
		{
			visit[i] = 1; //设置顶点为已访问  
			cout << G->verlist[i].vertex;
			EnQueue(&Q, i); //当前顶点的下标值进队  
			while (!QueueEmpty(Q)) //队列不为空  
			{
				DeQueue(&Q, &i); //出队  
				EdgeNode *p = G->verlist[i].firstedge; //指向下一个边表结点  
				while (p)
				{
					if (!visit[p->adjvex]) //如果是未访问的结点  
					{
						visit[p->adjvex] = 1;
						cout << "  " << G->verlist[p->adjvex].vertex << "  ";
						EnQueue(&Q, p->adjvex);
					}
					p = p->next; //指向下一个边表结点  
				}
			}
		}
	}
	cout << endl;
}
#endif