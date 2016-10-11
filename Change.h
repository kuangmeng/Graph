#pragma once
#ifndef Change_h
#define Change_h
#include"AMLGraph.h"
#include"MTGraph.h"
#include"ADJGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "MakeQueue.h"
#include "InOutFile.h"
using namespace std;
//���ڽӾ���ת�����ڽӱ�
ADJGraph * MTtoADJ(MTGraph *G) {
	int i;
	ADJGraph *g;
	g = (ADJGraph *)malloc(sizeof(ADJGraph));
	g->n = G->n; g->e = G->e;
	for (i = 0; i < G->n; i++) {    
		//���ڽӱ�������ͷ����ָ�����ó�ֵ
		g->verlist[i].vertex = G->vertex[i];
		g->verlist[i].firstedge = NULL;
	}
	for (i = 0; i<G->e; i++)
	{
		Insert(g, G->edge2[i][0], G->edge2[i][1]);
		Insert(g, G->edge2[i][1], G->edge2[i][0]);
	}
	return g;
}
//�ڽӾ���ת�ڽӶ��ر�
AMLGraph *MTtoAML(MTGraph *G) {
	AMLGraph *e;
	e = (AMLGraph *)malloc(sizeof(AMLGraph));
	e->e = G->e;
	e->n = G->n;
	int i, k;
	for (i = 0; i<e->n; i++)
	{
		e->adjmulist[i].data = G->vertex[i];
		e->adjmulist[i].firstedge = NULL;
	}
	for (k = 0; k<e->e; k++)
	{
		EBox *p = new EBox;
		p->ivex = G->edge2[k][0];
		p->jvex = G->edge2[k][1];
		p->ilink = e->adjmulist[G->edge2[k][0]].firstedge;
		p->jlink = e->adjmulist[G->edge2[k][1]].firstedge;
		e->adjmulist[G->edge2[k][0]].firstedge = e->adjmulist[G->edge2[k][1]].firstedge = p;
	}
	return e;
}
//�ڽӱ�ת�ڽӾ���
MTGraph * ADJtoMT(ADJGraph *G) {
	MTGraph *p;
	int i, j;
	p = (MTGraph *)malloc(sizeof(MTGraph));
	p->n = G->n;
	p->e = G->e;
	for (i = 0; i <G->n; i++) {
		p->vertex[i] = G->verlist[i].vertex;
	}
	EdgeNode *e;
	for (i = 0; i < G->n; i++) {
		for (j = 0; j <G->n; j++) {
			p->edge[i][j] = 0;
		}
	}
	for (i = 0; i <G->n; i++) {
		e = G->verlist[i].firstedge;
		while (e) {
			p->edge[i][e->adjvex] = 1;
			p->edge[e->adjvex][i] = 1;
			e = e->next;
		}
	}
	return p;
}
//�ڽӱ�ת�ڽӶ��ر�
AMLGraph *ADJtoAML(ADJGraph *G) {
	AMLGraph *e;
	e = (AMLGraph *)malloc(sizeof(AMLGraph));
	e->e = G->e;
	e->n = G->n;
	int i;
	for (i = 0; i<e->n; i++)
	{
		e->adjmulist[i].data = G->verlist[i].vertex;
		e->adjmulist[i].firstedge = NULL;
	}
	for (i = 0; i < G->e; i++) {
		EBox *p = new EBox;
		p->ivex = G->edge[i][0];
		p->jvex = G->edge[i][1];
		p->ilink = e->adjmulist[G->edge[i][0]].firstedge;
		p->jlink = e->adjmulist[G->edge[i][1]].firstedge;
		e->adjmulist[G->edge[i][0]].firstedge = e->adjmulist[G->edge[i][1]].firstedge = p;
	}
	return e;
}
//�ڽӶ��ر�ת�ڽӾ���
MTGraph *AMLtoMT(AMLGraph *G) {
	MTGraph *p;
	int i, j;
	p = (MTGraph *)malloc(sizeof(MTGraph));
	p->n = G->n;
	p->e = G->e;
	for (i = 0; i < G->n; i++) {
		p->vertex[i] = G->adjmulist[i].data;
	}
	EBox *e;
	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++) {
			p->edge[i][j] = 0;
		}
	}
	for (i = 0; i <G->n; i++) {
		e = G->adjmulist[i].firstedge;
		while (e) {
			p->edge[i][e->ivex] = 1;
			p->edge[e->ivex][i] = 1;
			p->edge[i][e->jvex] = 1;
			p->edge[e->jvex][i] = 1;
			e = e->jlink;
		}
	}
	for (i = 0; i < G->n; i++) {
		for (j = 0; j < G->n; j++) {
			if (i == j) p->edge[i][j] = 0;
		}
	}
	return p;
}
//�ڽӶ��ر�ת�ڽӱ�
ADJGraph *AMLtoADJ(AMLGraph* G) {
	ADJGraph *p;
	p = (ADJGraph *)malloc(sizeof(ADJGraph));
	p->n = G->n;
	p->e = G->e;
	int i, j, v;
	for (i = 0; i < G->n; i++) {
		p->verlist[i].vertex = G->adjmulist[i].data;
		p->verlist[i].firstedge = NULL;
	}
	for (v = 0; v<G->e; v++)
	{
		i = G->edge[v][0];
		j = G->edge[v][1];
		Insert(p, i, j);
		Insert(p, j, i);
	}
	return p;
}
#endif