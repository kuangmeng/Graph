#pragma once
#ifndef MakeQueue_h
#define MakeQueue_h
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#define NUM 100
using namespace std;
int visit[NUM];
//���ж���
typedef int QElemType;
typedef struct QNode {
	QElemType data;
	QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front, rear;
}LinkQueue;
//���г�ʼ��
int InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front) exit(-2);
	Q->front->next = NULL;
	return 1;
}
//�ж϶����Ƿ�Ϊ��
int QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) return 1;
	else return 0;
}
//�����
int EnQueue(LinkQueue *Q, QElemType e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(-2);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return 1;
}
//������
int DeQueue(LinkQueue *Q, QElemType *e) {
	QueuePtr p;
	if (Q->front == Q->rear) return 0;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p) Q->rear = Q->front;
	free(p);
	return 1;
}
#endif
