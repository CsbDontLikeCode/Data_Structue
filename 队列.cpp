#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;//队列元素类型

typedef struct QNode{//定义队列节点结构
	QElemType data;
	struct QNode* next;
}QNode;

typedef struct {
	QNode* front;//队头指针
	QNode* rear;//队尾指针
}LinkQuene;

void InitQuene(LinkQuene* Q) {//构建一个空队列Q
	Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
	if (!Q->front) exit(1);
	Q->front->next = NULL;
}

void EnQuene(LinkQuene* Q,QElemType e) {//元素入队列
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

QElemType DeQuene(LinkQuene* Q) {//元素出队列
	QElemType e;
	if (Q->front == Q->rear) exit(1);
	QNode* p;
	p = Q->front->next;
	e = p->data;
	Q->front->next = Q->front->next->next;
	free(p);
	return e;
}

int main() {
	QElemType e;

	LinkQuene Q;
	InitQuene(&Q);
	
	for (int i = 0; i < 5; i++) {
		printf("请输入插入元素:");
		scanf_s("%d", &e);
		EnQuene(&Q, e);
	}

	printf("依次输出队列中元素：");
	for (int i = 0; i < 5; i++) {
		e = DeQuene(&Q);
		printf("%d ", e);
	}
	

	return 0;
}