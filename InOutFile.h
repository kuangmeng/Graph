#pragma once
#ifndef InOutFile_h
#define InOutFile_h
#include"AMLGraph.h"
#include"MTGraph.h"
#include"ADJGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <iostream>
#pragma warning(disable:4996)
#define NUM 100
using namespace std;
int n, e;
int vertex[NUM];
int edge[NUM][2];
//�����ļ�
void InFile() {
	int i;
	ofstream MyFile;
	MyFile.open("Test.txt");
	cout << "����������ͼ�Ķ������������";
	cin >> n >> e ;
	MyFile << n <<endl<<e<<endl;
	for (i = 0; i < n; i++) {
		cout << "�������"<<i+1<<"�����㣺";
		cin >> vertex[i];
		MyFile << vertex[i]<<endl;
	}
	for (i = 0; i < e; i++) {
		cout << "�������" << i + 1 << "���ߣ�";
		cin >> edge[i][0] >> edge[i][1];
		MyFile << edge[i][0] << endl << edge[i][1]<<endl;
	}
	cout << "������Ϣ�������ļ��ѽ������ļ���ΪTest.txt !"<<endl;
	MyFile.close();
}
int message[NUM];
//��ȡ�ļ�
void OutFile() {
	freopen("Test.txt", "r", stdin);
	for (int i = 0; i <n+e*2+2; i++) {
		scanf("%d", &message[i]);
	}
	fclose(stdin);
	cout << "������Ϣ�Ѷ�����"<<endl;
}
//�ڽӾ�������ͼ
void CreateMTGraph2(MTGraph *G) {
	int a1, a2, i, j, k;
	G->n = message[0];
	G->e= message[1];
	for (i = 0; i < G->n; i++) {
		G->vertex[i]= message[i+2];
	}
	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++) {
			G->edge[i][j] = 0;
		}
	}
	for (k = 0; k < G->e; k++) {
		a1 = message[n + 2 + 2*k];
		a2= message[n+2+2*k+1];
		i = LocateVex(G, a1);
		j = LocateVex(G, a2);
		G->edge[i][j] = 1;
		G->edge[j][i] = 1;
	}
	cout << "�ڽӾ�������ͼ������" << endl;
}
//�ڽӱ�����ͼ
void CreateADJGraph2(ADJGraph * G)
{
	int v, a1, a2, i, j;
	G->n = message[0];
	G->e = message[1];
	for (v = 0; v<G->n; v++) {
		G->verlist[v].vertex=message[v+2];
		G->verlist[v].firstedge = NULL;
	}
	for (v = 0; v<G->e; v++)
	{
		a1 = message[n + 2 + v * 2];
		a2=message[n+2+v*2+1];
		i = LocateVex(G, a1);
		j = LocateVex(G, a2);
		Insert(G, i, j);
		Insert(G, j, i);
	}
	cout << "���ڽӱ�����ͼ������" << endl;
}
//�ڽӶ��ر�����ͼ
void AMLGraph::CreateAMLGraph2()
{
	int v1, v2;
	int i, j, k;
	n = message[0];
	e = message[1];
	for (i = 0; i<n; i++)
	{
		adjmulist[i].data=message[i+2];
		adjmulist[i].firstedge = NULL;
	}
	for (k = 0; k<e; k++)
	{  
		v1 = message[n+2+2*k];
		v2 = message[n + 2 + 2 * k + 1];
		i = LocateVex(v1);
		j = LocateVex(v2);
		edge[k][0] = i;
		edge[k][1] = j;
		EBox *p = new EBox;
		p->ivex = i;
		p->jvex = j;
		p->ilink = adjmulist[i].firstedge;
		p->jlink = adjmulist[j].firstedge;
		adjmulist[i].firstedge = adjmulist[j].firstedge = p;
	}
	cout << "�ڽӶ��ر�����ͼ��ɣ�\n" << endl;
}
#endif