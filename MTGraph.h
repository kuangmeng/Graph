#pragma once
#ifndef MTGraph_h
#define MTGraph_h
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "MakeQueue.h"
using namespace std;
typedef int VertexData;
typedef int EdgeData;
typedef struct {
	VertexData vertex[NUM];
	EdgeData edge[NUM][NUM];
	int n, e;
	int edge2[NUM][2];
}MTGraph;
//输入边节点判断是否在图内
int LocateVex(MTGraph *G,VertexData v)
{
	for (int i = 0; i<G->n; i++)
		if (G->vertex[i] == v)
			return i;
	return -1;
}
//以邻接矩阵形式建无向图
void CreateMTGraph(MTGraph *G) {
	int a1, a2, i,j,k;
	cout << "请输入无向图的顶点数和边数：";
	cin >> G->n >> G ->e;
	for (i = 0; i < G->n; i++) {
		printf("现在输入第%d个元素：", i + 1);
		cin >> G->vertex[i];
	}
	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++) {
			G->edge[i][j] = 0;
		}
	}
	for (k = 0; k < G->e; k++) {
		printf("现在输入第%d条边：", k + 1);
		cin >> a1 >> a2;
		i = LocateVex(G,a1);
		j = LocateVex(G, a2);
		while (i == -1 || j == -1)
		{
			cout << "两个顶点中有不符合要求的，请重新输入：";
			cin >> a1 >> a2;
			i = LocateVex(G,a1);
			j = LocateVex(G,a2);
		}
		G->edge2[k][0] = i;
		G->edge2[k][1] = j;
		G->edge[i][j] = 1;
		G->edge[j][i] = 1;
	}
	cout << "邻接矩阵建无向图结束！" << endl;
}
//输出邻接矩阵
void PrintGraph(MTGraph *G)
{
	int i, j;
	for (i = 0; i<G->n; i++)
	{
		for (j = 0; j < G->n; j++) {
			cout << " " << G->edge[i][j];
		}
		cout << endl;
	}
}
//深度遍历
void DFSearch(MTGraph *G, int i) {
	int j;
	cout << G->vertex[i] << "  ";
	visit[i] = 1;
	for (j = 0; j < G->n; j++) {
		if (G->edge[i][j] == 1 && !visit[i]) {
			DFSearch(G, j);
		}
	}
}
void DFSTraverse(MTGraph *G) {
	int v;
	for (v = 0; v < G->n; v++) {
		visit[v] = 0;
	}
	for (v = 0; v < G->n; v++) {
		if (!visit[v]) DFSearch(G, v);
	}
}
//深度非递归遍历
void DFSearch2(MTGraph *G, int i) {
	int j;
	cout << G->vertex[i] << "  ";
	visit[i] = 1;
	for (j = i+1; j <G->n; j++) {
		if (G->edge[i][j] == 1 && !visit[i]) {
			cout << G->vertex[j] << "  ";
			visit[j] = 1;
		}
	}
}
void DFSTraverse2(MTGraph *G) {
	int v;
	for (v = 0; v < G->n; v++) {
		visit[v] = 0;
	}
	for (v = 0; v < G->n; v++) {
		if (!visit[v]) DFSearch2(G, v);
	}
}
//广度遍历
void BFSTraverse(MTGraph *G) {
	int i, j, k;
	LinkQueue Q;
	for (i = 0; i < G->n; i++) visit[i] = 0;
	InitQueue(&Q);
	for (i = 0; i < G->n; i++) {
		if (0 == visit[i]) {
			visit[i] = 1;
			cout << G->vertex[i] << ' ';
			EnQueue(&Q, i);
			while (!QueueEmpty(Q)) {
				DeQueue(&Q, &j);
				for (k = 0; k < G->n; k++) {
					if (0 == visit[k]) {
						visit[k] = 1;
						cout << "-->" << G->vertex[k] << ' ';
						EnQueue(&Q, k);
					}
				}
			}
		}
	}
}
#endif