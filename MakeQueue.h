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
//队列定义
typedef int QElemType;
typedef struct QNode {
	QElemType data;
	QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front, rear;
}LinkQueue;
//队列初始化
int InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front) exit(-2);
	Q->front->next = NULL;
	return 1;
}
//判断队列是否为空
int QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) return 1;
	else return 0;
}
//入队列
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
//出队列
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
