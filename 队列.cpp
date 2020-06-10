#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;//����Ԫ������

typedef struct QNode{//������нڵ�ṹ
	QElemType data;
	struct QNode* next;
}QNode;

typedef struct {
	QNode* front;//��ͷָ��
	QNode* rear;//��βָ��
}LinkQuene;

void InitQuene(LinkQuene* Q) {//����һ���ն���Q
	Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
	if (!Q->front) exit(1);
	Q->front->next = NULL;
}

void EnQuene(LinkQuene* Q,QElemType e) {//Ԫ�������
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

QElemType DeQuene(LinkQuene* Q) {//Ԫ�س�����
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
		printf("���������Ԫ��:");
		scanf_s("%d", &e);
		EnQuene(&Q, e);
	}

	printf("�������������Ԫ�أ�");
	for (int i = 0; i < 5; i++) {
		e = DeQuene(&Q);
		printf("%d ", e);
	}
	

	return 0;
}